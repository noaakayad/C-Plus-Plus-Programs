#include "Swap.h"

/**
 * Swap the values of integers a and b (in-place)
 */
void swap(int & a, int & b) {
    /* YOUR CODE HERE */

    int save = a;
    a = b;
    b = save;
}
