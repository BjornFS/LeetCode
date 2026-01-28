#include <unordered_map>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> counts;

        for (char c : magazine) {
            counts[c] = counts[c] + 1;
        }

        for (char c : ransomNote) {
            auto it = counts.find(c);
            if (it == counts.end() || it->second == 0) {
                return false;
            }
            it->second = it->second -1;
        }
        return true;
};