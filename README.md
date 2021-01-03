# Pathological Path Tracer
Pathological is a multithreaded CPU path tracer that I have been
working on to learn C++ and a bit of math. This project is motivated
by general curiosity, and partially by a (very embarrasing) job
interview where I couldn't answer questions about the basics of C++
and statistics.  I am coming to this from C, so it is chock full of
non-idiomatic code and does not take advantage of some of the more
recent C++ features.

## Capabilities

![Sample render](/pics/early-render.png)
*Rendered in two hours using an early version of Pathological*

The major capabilities are currently:
- Sphere/Triangle primitives
- Hard coded scenes
- Multithreading
- Perfectly diffuse, mirror, and dielectric materials
- Export to NetPBM (P3, .ppm)
- Super basic benchmark

The next major tasks will be:
- Triangle mesh support
- .obj/.mtl file loading
- Scene loading
- Bidirectional path tracing
- Metropolis Light Transport
- Microfacet materials

## Project organization
```
.
├── resources       # Loadable resources, currently just shaders
├── inc             # Core project headers
│   ├── renderable  # Different renderable objects (sphere, mesh, etc.)
│   └── util        # Utilities for output and debugging
└── src             # Core project sources
    │               # organizaion matches 1:1 with ./inc
    ├── renderable
    └── util
```

## Benchmarking
Currently the benchmarks are nothing special, I have just been using
it to check if there are major performance regressions. To run this
benchmark, you can either run `./pathological bench`, or
`./runbench.sh <test_name>`. The `runbench.sh` script dumps the
results into a file `benchmarks.csv`, the first column is the million
paths per second of the triangle test, the second is that of the
sphere test.
