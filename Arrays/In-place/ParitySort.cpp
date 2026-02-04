#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int write = 0;
        int read = 0;

        for ( ; read < n ; ++read) {
            if (nums[read] % 2 == 0) {
                swap(nums[read], nums[write]);
                ++write;
            }
        }
    return nums;
};  