#include <vector>

using namespace std;

bool validMountainArray(vector<int>& arr) {
    
    int n = static_cast<int>(arr.size());
    if (n < 3) return false;                    // needs >2 elem's
    
    int i = 0;

    while (i + 1 < n && arr[i] < arr[i+1])      // check ascending
        ++i;
    
    if (i == 0 || i == n-1)                     // peak can't be first/last
        return false;
    
    while (i + 1 < n && arr[i] > arr[i+1])      // check descending
        i++;
    
    return i == n - 1;                          // traversed whole array? 
};