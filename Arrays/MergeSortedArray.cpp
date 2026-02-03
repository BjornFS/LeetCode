#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;      // Pointer for end of valid nums1 elements
    int j = n - 1;      // Pointer for end of nums2
    int k = m + n - 1;  // Pointer for the very end of nums1 capacity

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
        
    }
};
