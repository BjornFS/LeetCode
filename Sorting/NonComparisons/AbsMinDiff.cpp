#include <vector>
#include <algorithm>
#include <climits>

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> arr)
{
    std::sort(arr.begin(), arr.end());          // NOTE: uniques - gaps are between neighbours

    if (arr.size() < 2) return {};              // small input guard

    int minDist = INT_MAX;                      // init smallest gap
    std::vector<std::vector<int>> result;

    for (std::size_t i = 0; i + 1 < arr.size(); ++i) {
        int gap = arr[i + 1] - arr[i];

        if (gap < minDist) {                    // found a new, smaller gap
            minDist = gap;
            result.clear();                     // discard previous pairs
            result.push_back({arr[i], arr[i + 1]});
        }
        else if (gap == minDist) {
            result.push_back({arr[i], arr[i + 1]});
        }
    }

    return result;
}