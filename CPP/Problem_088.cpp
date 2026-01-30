#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

static const int KMAX = 12000;
static const int LIMIT = 2 * KMAX;
vector<int> best(KMAX + 1, INT_MAX);

void dfs(int start, int prod, int sum, int m) {
    int k = m + (prod - sum);
    if (k <= KMAX) best[k] = min(best[k], prod);

    for (int f = start; f * prod <= LIMIT; ++f) {
        dfs(f, prod * f, sum + f, m + 1);
    }
}

int main() {
    dfs(2, 1, 0, 0);

    unordered_set<int> uniq;
    for (int k = 2; k <= KMAX; ++k) uniq.insert(best[k]);

    long long ans = 0;
    for (int x : uniq) ans += x;

    cout << ans << "\n"; // 7587457
    return 0;
}
