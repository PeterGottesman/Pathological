#pragma once
#include <vector>
#include <string>
#include "vec3.h"

// OBJ staging container
struct ObjData {
    std::vector<Vec3> V;   // vertices (v)
    std::vector<Vec3> VN;  // normals  (vn)

    struct Tri {
        int v[3];          // vertex indices (0-based)
        int vn[3];         // normal indices (0-based)
    };
    std::vector<Tri> tris; // faces (f)
};

// Load .obj with: v, vn, f (supports "f a b c" and "f a//na b//nb c//nc"
ObjData load_obj_file(const std::string& path);
ObjData load_obj_stream(std::istream& istream);
