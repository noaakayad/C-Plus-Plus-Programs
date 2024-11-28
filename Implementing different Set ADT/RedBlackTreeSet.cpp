#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    /* YOUR CODE HERE */
    return rbt.size();
}

bool RedBlackTreeSet::find(const string & s) {
    /* YOUR CODE HERE */
    return rbt.find(s) != rbt.end();
}

void RedBlackTreeSet::insert(string s) {
    /* YOUR CODE HERE */
    if(!find(s)){
        rbt.insert(s);
    }
}

void RedBlackTreeSet::remove(const string & s) {
    /* YOUR CODE HERE */
    rbt.erase(s);
}

