#include <vector>
#include <unordered_set>

using namespace std;

bool checkIfExist(vector<int>& arr) {
    std::unordered_set<int> seen;               // use a hashset
    
    for (int x : arr) {                         // iterate array
        if (seen.count(2 * x))                  // check if 2x in set
            return true;                        
        if ((x & 1) == 0 && seen.count(x / 2))  // check if even AND x/2 in set (only int's)
            return true;
        seen.insert(x);                         // add x to set
    }
    return false;
};