#include <vector>

using namespace std;

void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    int possible_dups = 0;
    int last = n - 1;

    // 1. Find the number of zeros to be duplicated
    for (int i = 0; i <= last - possible_dups; i++) {
        if (arr[i] == 0) {
            // Edge case: if the zero is at the boundary and can't be duplicated
            if (i == last - possible_dups) {
                arr[last] = 0;
                last--;
                break;
            }
            possible_dups++;
        }
    }

    // 2. Backward pass to fill the vector
    int j = last; // The logical end of the "expanded" array that fits
    for (int i = j - possible_dups; i >= 0; i--) {
        if (arr[i] == 0) {
            arr[i + possible_dups] = 0;
            possible_dups--;
            arr[i + possible_dups] = 0;
        } else {
            arr[i + possible_dups] = arr[i];
        }
    }
};