#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

static int poly(int s, int n) {
    // ((s-2)n^2 - (s-4)n) / 2
    return ((s - 2) * n * n - (s - 4) * n) / 2;
}

static vector<int> generate4(int s) {
    vector<int> out;
    for (int n = 1;; n++) {
        int v = poly(s, n);
        if (v > 9999) break;
        if (v >= 1000) out.push_back(v);
    }
    return out;
}

int main() {
    vector<int> types = {3,4,5,6,7,8};

    unordered_map<int, vector<int>> nums;
    unordered_map<int, unordered_map<int, vector<int>>> edges;

    for (int s : types) {
        nums[s] = generate4(s);
        for (int x : nums[s]) {
            int pre = x / 100;
            int suf = x % 100;
            if (suf < 10) continue;
            edges[s][pre].push_back(x);
        }
    }

    long long answer = -1;
    vector<int> best;

    function<bool(vector<int>&, vector<bool>&, int, int)> dfs =
        [&](vector<int>& path, vector<bool>& used, int needPrefix, int startPrefix) -> bool {
            if ((int)path.size() == 6) {
                return needPrefix == startPrefix;
            }
            for (int si = 0; si < 6; si++) {
                if (used[si]) continue;
                int s = types[si];
                auto it = edges[s].find(needPrefix);
                if (it == edges[s].end()) continue;
                for (int x : it->second) {
                    used[si] = true;
                    path.push_back(x);
                    if (dfs(path, used, x % 100, startPrefix)) return true;
                    path.pop_back();
                    used[si] = false;
                }
            }
            return false;
        };

    for (int si = 0; si < 6; si++) {
        int startType = types[si];
        for (int start : nums[startType]) {
            int sp = start / 100, ss = start % 100;
            if (ss < 10) continue;
            vector<int> path = {start};
            vector<bool> used(6, false);
            used[si] = true;
            if (dfs(path, used, ss, sp)) {
                long long sum = 0;
                for (int v : path) sum += v;
                answer = sum;
                best = path;
                cout << answer << "\n"; // 28684
                return 0;
            }
        }
    }

    return 0;
}
