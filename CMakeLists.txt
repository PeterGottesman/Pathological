cmake_minimum_required(VERSION 3.25)

project(pathological VERSION 1.0 LANGUAGES CXX)

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
set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/vec3_test.cpp
)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${PROJECT_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES_FILES})
add_executable(vec3_test ${TEST_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE inc)
target_include_directories(vec3_test PRIVATE inc)

target_compile_options(${PROJECT_NAME} PRIVATE
    -ggdb         
    -Ofast        
    -Wall         
    -march=native
)

target_link_libraries(${PROJECT_NAME} PUBLIC
	GLEW
    	GL
    	glfw
	pthread
)
