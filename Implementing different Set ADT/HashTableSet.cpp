#include "Set.h"

/**
 * Implement the HashTableSet methods correctly
 */
unsigned int HashTableSet::size() {
    /* YOUR CODE HERE */
    return ht.size();
}

bool HashTableSet::find(const string & s) {
    /* YOUR CODE HERE */
    return ht.find(s) != ht.end();
}

void HashTableSet::insert(string s) {
    /* YOUR CODE HERE */
    if(!find(s)){
        ht.insert(s);
    }
}

void HashTableSet::remove(const string & s) {
    /* YOUR CODE HERE */
    ht.erase(s);
}

