#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());

    //Put each number in its correct position (value‑1)
    for (int i = 0; i < n; ++i) {
        // Keep swapping until the current element is either
        //   out of range               or
        //   already in the right spot, or
        //   a duplicate of the target position.
        while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    //Collect indices where the value is wrong
    std::vector<int> missing;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            missing.push_back(i + 1);
        }
    }
    return missing;
};