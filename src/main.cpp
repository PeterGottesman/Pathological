// Includes gl - do this first
#include "util/window.h"
#include <thread>
#include <cstring>

#include "pathological.h"

#include "util/argparse.h"
#include "util/benchmark.h"
#include "util/exporter.h"
#include "util/obj_loader.h"
#include "renderable/triangle.h"
#include "renderable/sphere.h"
#include "camera.h"
#include "scene.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const int SPP = 64;

int main(int argc, char **argv)
{
	// Arguments to parse
	bool benchmark;
    bool help;
	int width;
	int height;
	int nthreads;
	int spp;
	std::string obj_path;

	ArgParse parser(argc, argv);
	parser.add_arg("benchmark", "Run build in benchmarks", false);
	parser.add_arg("help", "Print help text", false);
	parser.add_arg("width", "Render image width", true, 'w');
	parser.add_arg("height", "Render image height", true, 'h');
	parser.add_arg("nthreads", "Number of render threads", true, 'n');
	parser.add_arg("samples", "Number of samples per pixel per frame", true, 's');
	parser.add_arg("obj", "Path to Wavefront OBJ file", true, 'o');

	if (parser.parse() != 0)
	{
		fprintf(stderr, "Failed to parse arguments\n");
        parser.print_help();
		return 1;
	}

	parser.get_arg("help", help, false);
    if (help)
    {
        parser.print_help();
        return 0;
    }

	parser.get_arg("benchmark", benchmark, false);
	parser.get_arg("width", width, WIDTH);
	parser.get_arg("height", height, HEIGHT);
	parser.get_arg("nthreads", nthreads, (int)std::thread::hardware_concurrency());
	parser.get_arg("samples", spp, SPP);
	parser.get_arg("obj", obj_path, std::string(""));

	

	if (benchmark)
	{
		printf("Running single threaded tests\n");
		Benchmark::bench_spheres();
		Benchmark::bench_tris();
		return 0;
	}

	Window win(width, height, "Pathological path tracer");

	Pathological app(width, height, spp, nthreads);
	Scene& sc = app.get_scene();
	Camera& cam = app.get_camera();

	// load Cornell box
	app.load_default_scene(sc, cam);

	// if obj is provided, remove spheres and insert mesh
	if (!obj_path.empty()) {
		try {
				// Load OBJ
				ObjData obj = load_obj_file(obj_path);
				

				// Material for the mesh
				
				Material* meshmat = new Lambertian({1.0, 1.0, 1.0}, {1.0,1.0,1.0});



				// Add triangles to the scene
				size_t added = 0;
				for (const auto& tri : obj.tris) {
					std::array<Vec3,3> verts = {
						obj.V[tri.v[0]],
						obj.V[tri.v[1]],
						obj.V[tri.v[2]]
					};

					std::array<Vec3,3> norms = { Vec3{0,0,0}, Vec3{0,0,0}, Vec3{0,0,0} };
					if (tri.vn[0] >= 0 && tri.vn[1] >= 0 && tri.vn[2] >= 0) {
						norms = { obj.VN[tri.vn[0]], obj.VN[tri.vn[1]], obj.VN[tri.vn[2]] };
					}

					sc.add_renderable(new Triangle(verts, norms, meshmat));
					++added;
				}

				std::printf("Added %zu triangles to Scene\n", added);
			}catch (const std::exception& e) {
				std::fprintf(stderr, "Error loading OBJ: %s\n", e.what());
				return 1;
			}
		
	}
	void *pixels = app.get_texture();
	NetPBM exp("traced.ppm", width, height, (Color *)pixels);

	app.add_exporter(&exp);
	std::thread app_thread(&Pathological::run, &app);

	while (!win.should_quit())
	{
		win.display_texture(width, height, (char *)pixels);

		// Update display at 15 FPS
		std::this_thread::sleep_for(
			std::chrono::duration<float, std::ratio<1, 1>>(1.0/15.0));
	}

	app.stop();
	app_thread.join();
}
