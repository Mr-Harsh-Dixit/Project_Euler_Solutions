#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

static const long long TARGET = 8000000;
static vector<long long> PRIMES = {2,3,5,7,11,13,17,19,23,29,31};

long long bestN = LLONG_MAX;

void dfs(int idx, int maxExp, long long n, long long prod) {
    if (prod > TARGET) {
        bestN = min(bestN, n);
        return;
    }
    if (idx >= (int)PRIMES.size() || n >= bestN) return;

    long long p = PRIMES[idx];
    long long val = 1;

    for (int e = 1; e <= maxExp; e++) {
        val *= p;
        long long nn = n * val;
        if (nn >= bestN) break;
        dfs(idx + 1, e, nn, prod * (2*e + 1));
    }
}

int main() {
    dfs(0, 60, 1, 1);
    cout << bestN << "\n"; // 9350130049860600
    return 0;
}
