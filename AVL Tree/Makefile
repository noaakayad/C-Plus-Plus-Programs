CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++17
OUTFILES=BinaryTreeTest

all: $(OUTFILES)

BinaryTreeTest: BinaryTreeTest.cpp BinaryTree.cpp BinaryTree.h
	$(CXX) $(CXXFLAGS) -o BinaryTreeTest BinaryTreeTest.cpp BinaryTree.cpp

clean:
	$(RM) $(OUTFILES) *.o
