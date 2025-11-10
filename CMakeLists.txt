cmake_minimum_required(VERSION 3.25)

project(pathological VERSION 1.0 LANGUAGES CXX)
enable_testing()

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

set(VEC3_SOURCES ${PROJECT_SOURCE_DIR}/tests/vec3_test.cpp
)
set(OBJ_LOADER_SOURCES  ${PROJECT_SOURCE_DIR}/tests/obj_loader_test.cpp
)


find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${PROJECT_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES_FILES})
add_executable(vec3_test ${VEC3_SOURCES})
add_test(NAME vec3_test COMMAND vec3_test)
add_executable(obj_loader_test ${OBJ_LOADER_SOURCES} ${SOURCES_FILES_NONMAIN})
add_test(NAME obj_loader_test COMMAND obj_loader_test)

set (passRegex "^Test passed" "^All ok")
set (failRegex "Error" "Fail")

include_directories(BEFORE inc)

target_compile_options(${PROJECT_NAME} PRIVATE
    -ggdb         
    -Ofast        
    -Wall         
    -march=native
)
target_compile_options(vec3_test PRIVATE
    -ggdb
    -Ofast
    -Wall
    -march=native
)

target_link_libraries(${PROJECT_NAME} PUBLIC
	GLEW::GLEW
    	GL
    	glfw
	pthread
)
target_link_libraries(obj_loader_test PUBLIC
        GLEW::GLEW
        GL
        glfw
        pthread
)

