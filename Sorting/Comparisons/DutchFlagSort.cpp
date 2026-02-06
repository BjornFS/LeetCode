#include <vector>

// One-pass, O(n)-space solution
void sortColors(vector<int>& nums) {
    int low = 0;                                    // end of the 0‑region
    int i   = 0;                                    // current element
    int high = static_cast<int>(nums.size()) - 1;   // start of the 2‑region

    while (i <= high) {
        if (nums[i] == 0) {                         // put 0 to the front
            std::swap(nums[low], nums[i]);
            ++low;
            ++i;
        }
        else if (nums[i] == 1) {                    // 1 is already in correct middle region
            ++i;
        }
        else {                                      // nums[i] == 2, move it to the back
            std::swap(nums[i], nums[high]);
            --high;                                 // element swapped from the back is unchecked
        }
    }
}