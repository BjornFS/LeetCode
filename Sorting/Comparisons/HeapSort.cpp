#include <vector>

std::vector<int> sortArray(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    // ----- Build max‑heap -----
    for (int i = n / 2 - 1; i >= 0; --i) {
        int idx = i;                    // start at node i
        while (true) {
            int largest = idx;
            int left    = 2 * idx + 1;
            int right   = 2 * idx + 2;

            if (left < n && nums[left] > nums[largest])
                largest = left;
            if (right < n && nums[right] > nums[largest])
                largest = right;

            if (largest == idx) break;   // heap property satisfied

            // swap idx with largest
            int tmp = nums[idx];
            nums[idx] = nums[largest];
            nums[largest] = tmp;

            idx = largest;                // continue sinking down
        }
    }

    // ----- Extraction phase -----
    for (int heapSize = n - 1; heapSize > 0; --heapSize) {
        // move current max to the end
        int tmp = nums[0];
        nums[0] = nums[heapSize];
        nums[heapSize] = tmp;

        // restore heap property for the reduced heap
        int idx = 0;
        while (true) {
            int largest = idx;
            int left    = 2 * idx + 1;
            int right   = 2 * idx + 2;

            if (left < heapSize && nums[left] > nums[largest])
                largest = left;
            if (right < heapSize && nums[right] > nums[largest])
                largest = right;

            if (largest == idx) break;

            int t = nums[idx];
            nums[idx] = nums[largest];
            nums[largest] = t;

            idx = largest;
        }
    }

    return nums;   // now sorted ascending
};