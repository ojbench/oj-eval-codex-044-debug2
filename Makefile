CXX := g++
CXXFLAGS := -std=gnu++17 -O2 -pipe -Wall -Wextra -Wpedantic
LDFLAGS :=

.PHONY: all clean

all: code

code: code.cpp
	$(CXX) $(CXXFLAGS) code.cpp -o code $(LDFLAGS)

clean:
	rm -f code *.o
