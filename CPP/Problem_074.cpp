#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    const int LIMIT = 1'000'000;

    int fact[10];
    fact[0] = 1;
    for (int i = 1; i <= 9; i++) fact[i] = fact[i - 1] * i;

    const int MAX = 7 * fact[9]; // 2,540,160
    vector<int> memo(MAX + 1, 0);

    auto nxt = [&](int x) -> int {
        if (x == 0) return fact[0];
        int s = 0;
        while (x) {
            s += fact[x % 10];
            x /= 10;
        }
        return s;
    };

    auto chain_len = [&](int start) -> int {
        vector<int> path;
        unordered_map<int,int> pos;
        pos.reserve(80);

        int x = start;
        while (true) {
            if (x <= MAX && memo[x] != 0) {
                int known = memo[x];
                for (int i = (int)path.size() - 1; i >= 0; --i) {
                    known += 1;
                    int v = path[i];
                    if (v <= MAX) memo[v] = known;
                }
                return (start <= MAX) ? memo[start] : (int)path.size() + memo[x];
            }

            auto it = pos.find(x);
            if (it != pos.end()) {
                int loopStart = it->second;
                int loopLen = (int)path.size() - loopStart;

                for (int i = loopStart; i < (int)path.size(); i++) {
                    int v = path[i];
                    if (v <= MAX) memo[v] = loopLen;
                }

                int dist = loopLen;
                for (int i = loopStart - 1; i >= 0; --i) {
                    dist += 1;
                    int v = path[i];
                    if (v <= MAX) memo[v] = dist;
                }

                return (start <= MAX) ? memo[start] : (int)path.size();
            }

            pos[x] = (int)path.size();
            path.push_back(x);
            x = nxt(x);
        }
    };

    int count = 0;
    for (int n = 1; n < LIMIT; n++) {
        if (chain_len(n) == 60) count++;
    }

    cout << count << "\n"; // 402
    return 0;
}
