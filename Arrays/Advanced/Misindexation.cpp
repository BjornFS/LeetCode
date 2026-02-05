#include <vector>

using namespace std;

int heightChecker(vector<int>& heights) {
    
    vector<int> expected = heights;
    sort(expected.begin(), expected.end());

    int misindexation = 0;

    for (int i = 0; i < static_cast<int>(heights.size()); ++i) {
        if (heights[i] != expected[i]) {
            ++misindexation;
        }

    }
    return misindexation;
};
