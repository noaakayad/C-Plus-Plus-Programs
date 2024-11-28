#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
    for(int i = 0; i < int(K); i++){
        function<unsigned int(const string &)> hf = hash_functions[i];
        unsigned int index = hf(s)%M;
        count[i][index] ++;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
    int est = numeric_limits<int>::max();
    for(int i = 0; i < int(K); i++){
        function<unsigned int(const string &)> hf = hash_functions[i];
        unsigned int index = hf(s)%M;
        int curr = count[i][index]%M;
        if(curr < est){
            est = curr;
        }
    }
    return est;
}
