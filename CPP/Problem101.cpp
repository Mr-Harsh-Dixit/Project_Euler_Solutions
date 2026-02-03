#include <iostream>
#include <vector>
using namespace std;

static long long u(long long n) {
    long long s = 0;
    long long sign = 1;
    long long p = 1; // n^0
    for (int i = 0; i <= 10; i++) {
        s += sign * p;
        sign = -sign;
        p *= n;
    }
    return s;
}

static long long comb_ll(int n, int r) {
    // small n (<=10), safe with long long
    if (r < 0 || r > n) return 0;
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}

int main() {
    vector<long long> vals(12, 0); // 1..11
    for (int n = 1; n <= 11; n++) vals[n] = u(n);

    long long ans = 0;

    for (int k = 1; k <= 10; k++) {
        vector<long long> diff(k);
        for (int i = 0; i < k; i++) diff[i] = vals[i + 1];

        vector<long long> first_diffs;
        first_diffs.reserve(k);
        first_diffs.push_back(diff[0]);

        for (int level = 1; level <= k - 1; level++) {
            for (int i = 0; i < k - level; i++) {
                diff[i] = diff[i + 1] - diff[i];
            }
            first_diffs.push_back(diff[0]);
        }

        long long pred = 0;
        for (int j = 0; j < k; j++) {
            pred += comb_ll(k, j) * first_diffs[j];
        }

        if (pred != vals[k + 1]) ans += pred;
    }

    cout << ans << "\n"; // 37076114526
    return 0;
}
