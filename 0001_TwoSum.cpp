#include <vector> 
#include <algorithm>    // for std::find

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    for (size_t idx = 0; idx < nums.size(); ++idx) {
        int num = nums[idx];
        int complement = target - num;
        auto it = find(nums.begin() + idx + 1, nums.end(), complement);
        if (it != nums.end()) {
            size_t compIdx = static_cast<size_t>(it - nums.begin());
            return {static_cast<int>(idx), static_cast<int>(compIdx)};
        }
    }
    return {};
};

