#include <vector>

using namespace std;


int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int writeIdx = 1;    // first element is always kept
    for (std::size_t readIdx = 1; readIdx < nums.size(); ++readIdx) {
        if (nums[readIdx] != nums[readIdx - 1]) {
            nums[writeIdx] = nums[readIdx];
            writeIdx++;
        }
    }
    return writeIdx;
};