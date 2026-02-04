#include <vector>

using namespace std;

vector<int> replaceElements(vector<int>& arr) {        
    int max_val = -1; 
    int current_val = max_val;  

    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
        current_val = arr[i];
        arr[i] = max_val;

        if (current_val > max_val) {
            max_val = current_val;
        }
    }
    return arr;
};