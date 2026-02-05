#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int thirdMax(const vector<int>& nums) {

    unordered_set<int> uniq(nums.begin(), nums.end()); // sort uniques : uniques
    vector<int> vals(uniq.begin(), uniq.end());        // sort uniques : hash-to-vec
    sort(vals.begin(), vals.end(), greater<int>());    // sort uniques : sort

    if (vals.size() >= 3) return vals[2];
    
    return vals[0];
};