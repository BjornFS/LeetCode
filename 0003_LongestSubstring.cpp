#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    
    std::unordered_map<char, int> window;

    int slowptr             = 0;
    int longestSubstring    = 0;

    for (int fastptr = 0; fastptr < static_cast<int>(s.size()); ++fastptr) {
        char c = s[fastptr];
        
        if (window.count(c)) {
            slowptr = std::max(slowptr, window[c] +1);
        }
        window[c] = fastptr;
        longestSubstring = std::max(longestSubstring, fastptr - slowptr +1 );
    }

    return longestSubstring;
}