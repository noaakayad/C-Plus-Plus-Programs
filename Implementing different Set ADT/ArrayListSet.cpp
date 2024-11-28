#include "Set.h"
#include <algorithm>

/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    /* YOUR CODE HERE */
    return arr.size();
}

bool ArrayListSet::find(const string & s) {
    /* YOUR CODE HERE */
    return std::find(arr.begin(), arr.end(), s) != arr.end();
}

void ArrayListSet::insert(string s) {
    /* YOUR CODE HERE */
    if(!(find(s))){
        arr.push_back(s);
    }
}

void ArrayListSet::remove(const string & s) {
    /* YOUR CODE HERE */
    auto it = std::find(arr.begin(), arr.end(), s);

    if(it != arr.end()){
        arr.erase(it);
    }
}

