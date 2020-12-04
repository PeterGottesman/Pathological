SOURCES=$(wildcard src/*.cpp)
OBJS=$(SOURCES:src/%.cpp=build/%.o)
EXEC=pathological

LIBS=glfw3 glew 

CXX=clang++
CFLAGS=-ggdb -O3 $(pkg-config --cflags $(LIBS)) -Wall -fopenmp
CFLAGS+=-I./inc
LDFLAGS=`pkg-config --libs $(LIBS)`

default: build/ $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^

build/:
	[ -d ./build ] || mkdir build

build/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build

.PHONY: default clean
