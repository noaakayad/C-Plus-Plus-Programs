CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++17
OUTFILES=SuffixArrayTest

all: $(OUTFILES)

SuffixArrayTest: SuffixArrayTest.cpp SuffixArray.cpp SuffixArray.h
	$(CXX) $(CXXFLAGS) -o SuffixArrayTest SuffixArrayTest.cpp SuffixArray.cpp

clean:
	$(RM) $(OUTFILES) *.o
