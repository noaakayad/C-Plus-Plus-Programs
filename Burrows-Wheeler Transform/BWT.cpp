#include <string>
#include "BWT.h"
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    /* YOUR CODE HERE */

    int n = s.length();
    string* bw = new string[n];
    bw[0] = s;

    for(int i = 1; i < n; i++){
        bw[i] = bw[i-1].substr(n-1) + bw[i-1].substr(0, n-1);
    }

    int min_idx; 
    string temp; 

    for (int i = 0; i < n - 1; i++) {

        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (bw[j] < bw[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            temp = bw[min_idx];
            bw[min_idx] = bw[i];
            bw[i] = temp;
        }
    }

    string result;

    for(int i = 0; i < n; i++){
        result += bw[i][n-1];
    }

    return result;
}
