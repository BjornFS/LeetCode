#include <vector>
#include <string>

std::vector<int> smallestTrimmedNumbers(std::vector<std::string>& nums, std::vector<std::vector<int>>& queries) {
    int n = nums.size();
    std::vector<int> answer;
    answer.reserve(queries.size());

    for (const auto& q : queries) {
        int k = q[0];
        int trim = q[1];

        std::vector<std::pair<std::string,int>> trimmed;
        trimmed.reserve(n);

        for (int i = 0; i < n; i++) {
            // take rightmost `trim` characters
            std::string t = nums[i].substr(nums[i].size() - trim);
            trimmed.push_back({t, i});
        }

        // sort by trimmed value, then by original index
        sort(trimmed.begin(), trimmed.end(),
                [](const std::pair<std::string,int>& a, const std::pair<std::string,int>& b) {
                    if (a.first != b.first) return a.first < b.first;
                    return a.second < b.second;
                });

        answer.push_back(trimmed[k - 1].second);
    }

    return answer;
};