#include <bits/stdc++.h>
using namespace std;

static const int MAX_K = 200;
static const int INF = 1e9;

int bestArr[MAX_K + 1];

static bool done() {
    for (int k = 1; k <= MAX_K; k++) {
        if (bestArr[k] == INF) return false;
    }
    return true;
}

static void dfs(vector<int>& chain, int depth, int limit) {
    int x = chain.back();
    if (depth < bestArr[x]) bestArr[x] = depth;
    if (depth == limit) return;

    for (int i = (int)chain.size() - 1; i >= 0; i--) {
        int nxt = x + chain[i];
        if (nxt <= x || nxt > MAX_K) continue;
        int nd = depth + 1;
        if (nd >= bestArr[nxt]) continue;

        chain.push_back(nxt);
        dfs(chain, nd, limit);
        chain.pop_back();
    }
}

int main() {
    for (int i = 0; i <= MAX_K; i++) bestArr[i] = INF;
    bestArr[1] = 0;

    int limit = 0;
    while (true) {
        vector<int> chain;
        chain.push_back(1);
        dfs(chain, 0, limit);
        if (done()) break;
        limit++;
    }

    long long sum = 0;
    for (int k = 1; k <= MAX_K; k++) sum += bestArr[k];
    cout << sum << "\n"; // 1582
    return 0;
}
