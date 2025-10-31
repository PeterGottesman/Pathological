#include "util/obj_loader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream>
using namespace std;

bool test_success = true;

//CheckVec3Expected from vec3_test.cpp

bool CheckVec3Expected(Vec3 a, float i, float j, float k, std::string on_fail) {
  bool succeed = true;
  if (a.x != i) {
    std::cerr << on_fail << ": x val differs " << a.x << " != " <<  i  << std::endl;
    succeed = false;
  }

  if (a.y != j) {
    std::cerr << on_fail << ": y val differs " << a.y << " != " <<  j  << std::endl;
    succeed = false;
  }

  if (a.z != k) {
    std::cerr << on_fail << ": z val differs " << a.z << " != " <<  k  << std::endl;
    succeed = false;
  }

  test_success = succeed && test_success;
  return succeed;
}

bool test(){
    std::string testdata = "v 0.0 0.0 0.0\n"
    "v 0.0 0.0 1.0\n"
    "v 0.0 1.0 0.0\n"
    "vn 0.0 0.0 1.0\n"
    "vn 1.0 0.0 1.0\n"
    "vn 0.0 1.0 1.0\n"
    "f 1//1 2//2 3//3\n";

    istringstream test_data_stream(testdata);

    ObjData output = load_obj_stream(test_data_stream);

    //test output of load_obj_stream
    //Vec3 v matches defined in test data (correct # of elements)
    //check ind. element to see if match in test data

    bool succeed = true;

    if(output.V.size()!=3){
        std::cerr << "Error: Face must have exactly 3 vertices";
        succeed = false;
    }

    if(output.VN.size()!=3){
        std::cerr << "Error: Face must have exactly 3 vertex normals";
        succeed = false;
    }

    if(output.tris.size()!=1){
        std::cerr << "Error: Face must have exactly one tris";
        succeed = false;
    }
    const auto& tris0 = output.tris[0];
    CheckVec3Expected(output.V[0], 0, 0, 0, "Failed output.v is incorrect");
    CheckVec3Expected(output.V[1], 0, 0, 1, "Failed output.v is incorrect");
    CheckVec3Expected(output.V[2], 0, 1, 0, "Failed output.v is incorrect");

    CheckVec3Expected(output.VN[0], 0, 0, 1, "Failed output.vn is incorrect");
    CheckVec3Expected(output.VN[1], 1, 0, 1, "Failed output.vn is incorrect");
    CheckVec3Expected(output.VN[2], 0, 1, 1, "Failed output.vn is incorrect");

    //refer to line 37 for formating on tris coordinates
    CheckVec3Expected(output.V[tris0.v[0]], 0,0,0, "Tri[0] v[0] points to wrong vertex");
    CheckVec3Expected(output.V[tris0.v[1]], 0,0,0, "Tri[0] v[1] points to wrong vertex");
    CheckVec3Expected(output.V[tris0.v[2]], 0,0,0, "Tri[0] v[2] points to wrong vertex");
    CheckVec3Expected(output.V[tris0.vn[0]], 0,0,0, "Tri[0] v[0] points to wrong vertex");
    CheckVec3Expected(output.V[tris0.vn[1]], 0,0,0, "Tri[0] v[1] points to wrong vertex");
    CheckVec3Expected(output.V[tris0.vn[2]], 0,0,0, "Tri[0] v[2] points to wrong vertex");


    return succeed;

}



int main(){
    test_success = test() && test_success;
    if (test_success){
        std::cerr << "Success!" << std::endl;
        return 0;
    }
    else{
        return 1;
    }
} 