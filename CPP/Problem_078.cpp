#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MOD = 1'000'000;

    vector<int> p;
    p.reserve(60000);
    p.push_back(1); // p[0]

    for (int n = 1; ; n++) {
        long long total = 0;
        for (int k = 1; ; k++) {
            int g1 = k * (3 * k - 1) / 2;
            if (g1 > n) break;
            int g2 = k * (3 * k + 1) / 2;

            int sign = (k & 1) ? 1 : -1;

            total += sign * p[n - g1];
            if (g2 <= n) total += sign * p[n - g2];
        }

        int val = (int)(total % MOD);
        if (val < 0) val += MOD;

        p.push_back(val);
        if (val == 0) {
            cout << n << "\n"; // 55374
            return 0;
        }
    }
}
