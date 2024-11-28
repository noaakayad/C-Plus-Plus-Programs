#include <string>
#include <vector>
#include "SuffixArray.h"
using namespace std;

/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
    /* YOUR CODE HERE */

    vector<unsigned int> sa;
    for(int i = 0; i < s.length(); i++){
        sa.push_back(i);
    }

    int min_idx; 
    unsigned int temp; 

    for (int i = 0; i < s.length() - 1; i++) {

        min_idx = i;
        for (int j = i + 1; j < s.length(); j++) {
            if (s.substr(sa[j]) < s.substr(sa[min_idx])) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            temp = sa[min_idx];
            sa[min_idx] = sa[i];
            sa[i] = temp;
        }
    }

    return sa;
}
