#include <vector>
#include <unordered_map>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    // Step 1: Count frequencies
    std::unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    size_t n = nums.size();
    size_t k_sz = static_cast<size_t>(k);

    // Step 2: Create buckets: index = frequency
    std::vector<std::vector<int>> buckets(n + 1);
    for (auto& [num, f] : freq) buckets[f].push_back(num);

    // Step 3: Collect top k frequent elements
    std::vector<int> result;
    for (size_t i = n; i > 0 && result.size() < k_sz; --i) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k_sz) break;
        }
    }

    return result;
}