#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
        int running_sum = 0;
        vector<int> vec;
        vec.reserve(nums.size()); 

        for (size_t i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            vec.push_back(running_sum);
        };
        return vec;
};