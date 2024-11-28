CXX=g++
CXXFLAGS=-Wall -pedantic -g -O0 -std=c++17
OUTFILES=FastSagaTest

all: $(OUTFILES)

FastSagaTest: FastSagaTest.cpp FastSaga.cpp FastSaga.h
	$(CXX) $(CXXFLAGS) -o FastSagaTest FastSagaTest.cpp FastSaga.cpp

clean:
	$(RM) $(OUTFILES) *.o
