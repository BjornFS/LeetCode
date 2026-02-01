#include <vector>
#include <string> // for std::to_string

using namespace std;

int findNumbers(vector<int>& nums) {
        int counter = 0;
        for (int val : nums) { 
            if (to_string(val).size() % 2 == 0) {
                ++counter;
            }
        }
    return counter;
}