#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    for (int digitsLen = 1;; digitsLen++) {
        unordered_map<string, pair<int, long long>> seen;
        seen.reserve(100000);

        long long n = 1;
        while ((int)to_string(n*n*n).size() < digitsLen) n++;

        while (true) {
            long long c = n*n*n;
            string s = to_string(c);
            if ((int)s.size() > digitsLen) break;

            sort(s.begin(), s.end());
            auto it = seen.find(s);
            if (it == seen.end()) {
                seen.emplace(s, make_pair(1, c)); // first is smallest
            } else {
                it->second.first++;
            }
            n++;
        }

        long long best = -1;
        for (auto &kv : seen) {
            int cnt = kv.second.first;
            long long smallest = kv.second.second;
            if (cnt == 5) {
                if (best == -1 || smallest < best) best = smallest;
            }
        }

        if (best != -1) {
            cout << best << "\n"; // 127035954683
            return 0;
        }
    }
}
