#include <vector>

using namespace std;

void moveZeroes(std::vector<int>& nums) {
    int write = 0;

    // First pass: pull all non‑zero elements forward, preserving order
    for (int x : nums) {
        if (x != 0) {
            nums[write] = x;
            ++write;
        }
    }

    // Second pass: fill the rest of the array with zeros
    while (write < static_cast<int>(nums.size())) {
        nums[write] = 0;
        ++write;
    }
};