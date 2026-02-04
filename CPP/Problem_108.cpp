#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const vector<int> PRIMES = {2,3,5,7,11,13,17,19,23,29};
static const long long TARGET = 2000;

long long bestN = (1LL<<62);

void dfs(int idx, int maxExp, long long n, long long divprod) {
    if (divprod > TARGET) {
        bestN = min(bestN, n);
        return;
    }
    if (idx >= (int)PRIMES.size() || n >= bestN) return;

    long long p = PRIMES[idx];
    long long val = 1;
    for (int e = 1; e <= maxExp; e++) {
        val *= p;
        if (n > bestN / val) break;  // Check for overflow
        long long nn = n * val;
        if (nn >= bestN) break;
        dfs(idx + 1, e, nn, divprod * (2*e + 1));
    }
}

int main() {
    dfs(0, 60, 1, 1);
    cout << bestN << "\n"; // 180180
    return 0;
}
