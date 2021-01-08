SOURCE_DIRS=$(shell find ./src/ -type d)
BUILD_DIRS=$(SOURCE_DIRS:./src/%=./build/%)

SOURCES=$(shell find ./src/ -type f -iname "*.cpp")
OBJS=$(SOURCES:./src/%.cpp=build/%.o)
EXEC=pathological

LIBS=glfw3 glew 

CXX=g++
CFLAGS=-ggdb -Ofast $(pkg-config --cflags $(LIBS)) -Wall
CFLAGS+=-I./inc -march=native
LDFLAGS=`pkg-config --libs $(LIBS)` -lpthread

default: $(BUILD_DIRS) $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIRS):
	[ -d "$@" ] || mkdir $@

build/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf build pathological

.PHONY: default clean
