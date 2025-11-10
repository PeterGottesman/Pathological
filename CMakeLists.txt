cmake_minimum_required(VERSION 3.25)

project(pathological VERSION 1.0 LANGUAGES CXX)
enable_testing()

#All source files that are needed for pathological executable
set(SOURCES_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp
                  ${PROJECT_SOURCE_DIR}/src/camera.cpp
                  ${PROJECT_SOURCE_DIR}/src/pathological.cpp
                  ${PROJECT_SOURCE_DIR}/src/randgen.cpp
                  ${PROJECT_SOURCE_DIR}/src/renderthread.cpp
                  ${PROJECT_SOURCE_DIR}/src/scene.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/argparse.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/benchmark.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/netpbm.cpp
		  ${PROJECT_SOURCE_DIR}/src/util/window.cpp
		  ${PROJECT_SOURCE_DIR}/src/util/obj_loader.cpp
                  ${PROJECT_SOURCE_DIR}/src/material/dielectric.cpp
                  ${PROJECT_SOURCE_DIR}/src/material/mirror.cpp
                  ${PROJECT_SOURCE_DIR}/src/material/lambertian.cpp
)

#Source files minus main used for test executables
set(SOURCES_FILES_NONMAIN
       		  ${PROJECT_SOURCE_DIR}/src/camera.cpp
                  ${PROJECT_SOURCE_DIR}/src/pathological.cpp
                  ${PROJECT_SOURCE_DIR}/src/randgen.cpp
                  ${PROJECT_SOURCE_DIR}/src/renderthread.cpp
                  ${PROJECT_SOURCE_DIR}/src/scene.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/argparse.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/benchmark.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/netpbm.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/window.cpp
                  ${PROJECT_SOURCE_DIR}/src/util/obj_loader.cpp
                  ${PROJECT_SOURCE_DIR}/src/material/dielectric.cpp
                  ${PROJECT_SOURCE_DIR}/src/material/mirror.cpp
                  ${PROJECT_SOURCE_DIR}/src/material/lambertian.cpp
)
set(OBJ_LOADER_SOURCES  ${PROJECT_SOURCE_DIR}/tests/obj_loader_test.cpp
)


find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${PROJECT_BINARY_DIR})

link_libraries(GLEW::GLEW GL glfw pthread)

add_compile_options(-ggdb -Ofast -Wall -march=native)

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

set (passRegex "^Test passed" "^All ok")
set (failRegex "Error" "Fail")

#Creates a test with the given test cpp file
function(create_test_executable TEST_NAME TEST_CPP)
	set(NEW_SOURCES ${TEST_CPP})
	add_executable(${TEST_NAME} ${NEW_SOURCES} ${SOURCES_FILES_NONMAIN})
	add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
	return()
endfunction()

# To create an test executable call the function, give it a name, and give it the path to the test cpp file
create_test_executable(vec3_test ${PROJECT_SOURCE_DIR}/tests/vec3_test.cpp)
create_test_executable(obj_loader_test ${PROJECT_SOURCE_DIR}/tests/obj_loader_test.cpp)

include_directories(BEFORE inc)
