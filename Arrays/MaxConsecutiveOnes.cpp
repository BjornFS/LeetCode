#include <vector>
#include <algorithm> // for std::max

using namespace std;

int findMaxConsecutiveOnes(const vector<int>& nums) {
        int max_count = 0;
        int counter   = 0;

        for (int val : nums) {
            if (val == 1) {
                ++counter;
            } else {
                max_count = max(max_count, counter);
                counter = 0;
            }
        }

        max_count = max(max_count, counter);

        return max_count;
};
