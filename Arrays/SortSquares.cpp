#include <vector>
#include <algorithm> // for std::sort

using namespace std;

vector<int> sortedSquares(const vector<int>& nums) {
        vector<int> result;
        result.reserve(nums.size());

        for (int x : nums) {
            result.push_back(x * x);
        }

        sort(result.begin(), result.end());
        
        return result;
};