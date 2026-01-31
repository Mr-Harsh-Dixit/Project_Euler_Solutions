#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    const int N = 1'000'000;

    vector<int> sumDiv(N + 1, 0);
    for (int i = 1; i <= N / 2; i++) {
        for (int j = i * 2; j <= N; j += i) sumDiv[j] += i;
    }

    vector<char> processed(N + 1, 0);

    int bestLen = 0;
    int bestMin = INT_MAX;

    vector<int> path;
    path.reserve(256);

    for (int start = 2; start <= N; start++) {
        if (processed[start]) continue;

        unordered_map<int,int> local;
        local.reserve(128);

        path.clear();
        int cur = start;

        while (cur >= 1 && cur <= N && !processed[cur] && !local.count(cur)) {
            local[cur] = (int)path.size();
            path.push_back(cur);
            cur = sumDiv[cur];
        }

        if (local.count(cur)) {
            int idx = local[cur];
            int clen = (int)path.size() - idx;
            int cmin = INT_MAX;
            for (int k = idx; k < (int)path.size(); k++) cmin = min(cmin, path[k]);

            if (clen > bestLen || (clen == bestLen && cmin < bestMin)) {
                bestLen = clen;
                bestMin = cmin;
            }
        }

        for (int v : path) processed[v] = 1;
    }

    cout << bestMin << "\n"; // 14316
    return 0;
}
