#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    // `writeIdx` points to the position where the next non‑val element
    // should be written.
    int writeIdx = 0;

    for (int x : nums) {
        if (x != val) {
            nums[writeIdx++] = x;   // keep element
        }
    }

    // Elements beyond `writeIdx` are irrelevant.
    return writeIdx;   // new length
};