#include <iostream>
#include "vec3.h"

bool test_success = true;

bool CheckVec3Expected(Vec3 a, float i, float j, float k, std::string on_fail) {
  bool succeed = true;
  if (a.x != i) {
    std::cerr << on_fail << ": x val differs " << a.x << " != " << " i " << std::endl;
    succeed = false;
  }

  if (a.y != j) {
    std::cerr << on_fail << ": ... " << a.y << " != " << " j " << std::endl;
    succeed = false;
  }

  if (a.z != k) {
    std::cerr << on_fail << ": ... " << a.z << " != " << " k " << std::endl;
    succeed = false;
  }

  test_success = succeed && test_success;
  return succeed;
}

bool TestConstruct() {
  Vec3 a = Vec3();
  CheckVec3Expected(a, 0, 0, 0, "Failed default constructor!");

  Vec3 b = Vec3(1.5);
  CheckVec3Expected(b, 1.5, 1.5, 1.5, "Failed 1 arg constructor!");

  Vec3 c = Vec3(1.5, 2.5, 3.5);
  CheckVec3Expected(c, 1.5, 2.5, 3.5, "Failed 3 arg constructor!");

  return true;
}

int main(int argc, char **argv) {
  test_success = TestConstruct() && test_success;
  if (test_success) {
    std::cerr << "Success!!" << std::endl;
    return 0;
  } else {
    return 1;
  }
}
