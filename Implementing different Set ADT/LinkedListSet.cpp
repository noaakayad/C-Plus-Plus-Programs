#include "Set.h"
#include <algorithm>

/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    /* YOUR CODE HERE */
    return linked.size();
}

bool LinkedListSet::find(const string & s) {
    return std::find(linked.begin(), linked.end(), s) != linked.end();
}

void LinkedListSet::insert(string s) {
    /* YOUR CODE HERE */
    if(!find(s)){
        linked.push_front(s);
    }
}

void LinkedListSet::remove(const string & s) {
    /* YOUR CODE HERE */
    linked.remove(s);
}
