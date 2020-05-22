CXXFLAGS += -std=c++17 -O3
# CXXFLAGS += -g -pedantic -Wall -std=c++17 -Og

all: cacheTest

cacheTest: main.cpp cache.h
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: all clean

clean:
	rm -f cacheTest
