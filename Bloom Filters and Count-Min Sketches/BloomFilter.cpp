#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */
    for(int i = 0; i < int(K); i++){
        function<unsigned int(const string &)> hf = hash_functions[i];
        unsigned int index = hf(s)%M;
        bits[index] = true;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */
    for(int i = 0; i < int(K); i++){
        function<unsigned int(const string &)> hf = hash_functions[i];
        unsigned int index = hf(s)%M;
        if(!bits[index]){
            return false;
        }
    }
    return true;
}
