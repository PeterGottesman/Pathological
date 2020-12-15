SOURCES=$(wildcard src/*.cpp)
OBJS=$(SOURCES:src/%.cpp=build/%.o)
EXEC=pathological

LIBS=glfw3 glew 

CXX=g++
CFLAGS=-ggdb -Ofast $(pkg-config --cflags $(LIBS)) -Wall
CFLAGS+=-I./inc -march=native
LDFLAGS=`pkg-config --libs $(LIBS)` -lpthread

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
