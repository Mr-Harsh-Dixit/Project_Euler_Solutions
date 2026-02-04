#include <iostream>
#include <algorithm>
using namespace std;

static long long comb_ll(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}

static long long catalan(int k) {
    return comb_ll(2*k, k) / (k + 1);
}

static long long needed_tests(int n) {
    long long total = 0;
    for (int k = 2; k <= n/2; k++) {
        long long ways_pick = comb_ll(n, 2*k);
        long long splits = comb_ll(2*k, k);
        long long noncross = catalan(k);
        long long need = (splits - 2*noncross) / 2;
        total += ways_pick * need;
    }
    return total;
}

int main() {
    cout << needed_tests(12) << "\n"; // 21384
    return 0;
}
