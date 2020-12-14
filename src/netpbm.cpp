#include <fstream>

#include "exporter.h"

bool NetPBM::export_image(void) const
{
	std::ofstream file;
	file.open(filename);
	file << "P3 " << width << " " << height << " " << range << "\n";

	int i;
	for (int r = 0; r < height; r++)
	{
		i = (height-r-1) * width;
		for (int c = 0; c < width; ++c)
		{
			unsigned r, g, b;
			r = (unsigned)(image[i].r * (range+1));
			g = (unsigned)(image[i].g * (range+1));
			b = (unsigned)(image[i].b * (range+1));

			r = r > range ? range : r;
			g = g > range ? range : g;
			b = b > range ? range : b;

			file << r << " " << g << " " << b;
			if (i%5 == 0)
				file << "\n";
			else
				file << " ";

			i++;
		}
	}

	file.close();
	return true;
}
