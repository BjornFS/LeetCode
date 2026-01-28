#include <vector>
#include <algorithm>    // for std::max_element

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> wealths;
        wealths.reserve(accounts.size()); // avoid repeated reallocations

        for (size_t i = 0; i < accounts.size(); ++i) {
            int sum = 0;
            for (size_t j = 0; j < accounts[i].size(); ++j) {
                sum += accounts[i][j];
            }
            wealths.push_back(sum);
        }
        auto max_it = max_element(wealths.begin(), wealths.end());
        return *max_it;
};