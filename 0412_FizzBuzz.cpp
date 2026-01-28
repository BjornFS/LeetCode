#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<string> fizzBuzz(int n) {
        const vector<pair<int, string>> rules = {
            {3, "Fizz"}, 
            {5, "Buzz"}
            };

        vector<string> answer;
        answer.reserve(static_cast<size_t>(n));

        for (int i = 1; i <= n; ++i) {
            string out;

            for (const auto& r : rules) {
                if (i % r.first == 0) {
                    out += r.second;
                }
            }

            if (out.empty()) {
                out = to_string(i);
            }

            answer.push_back(std::move(out));
        }

        return answer;
};