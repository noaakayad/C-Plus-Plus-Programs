CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++17
OUTFILES= compress uncompress

all: $(OUTFILES)

compress: compress.cpp Helper.cpp HCTree.cpp int24.cpp Helper.hpp HCTree.hpp int24.cpp
	$(CXX) $(CXXFLAGS) -o compress compress.cpp Helper.cpp HCTree.cpp int24.cpp

uncompress: uncompress.cpp Helper.cpp HCTree.cpp int24.cpp Helper.hpp HCTree.hpp int24.cpp
	$(CXX) $(CXXFLAGS) -o uncompress uncompress.cpp Helper.cpp HCTree.cpp int24.cpp

gprof: compress.cpp uncompress.cpp Helper.cpp HCTree.cpp int24.cpp Helper.hpp HCTree.hpp int24.cpp
	make clean
	$(CXX) $(CXXFLAGS) -pg -o compress compress.cpp Helper.cpp HCTree.cpp int24.cpp
	$(CXX) $(CXXFLAGS) -pg -o uncompress uncompress.cpp Helper.cpp HCTree.cpp int24.cpp

clean:
	rm -f $(OUTFILES) *.o

