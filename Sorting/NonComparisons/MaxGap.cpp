#include <vector>

int maximumGap(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    if (nums.size() < 2) return {};             // small input guard
    int maxDist = 0;
    
    for (std::size_t i = 0; i + 1 < nums.size(); ++i) {
        int gap = nums[i+1] - nums[i];
        if (gap > maxDist) maxDist = gap;
    }
    return maxDist;
};
