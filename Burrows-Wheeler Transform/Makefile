CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++17
OUTFILES=BWTTest

all: $(OUTFILES)

BWTTest: BWTTest.cpp BWT.cpp BWT.h
	$(CXX) $(CXXFLAGS) -o BWTTest BWTTest.cpp BWT.cpp

clean:
	$(RM) $(OUTFILES) *.o
