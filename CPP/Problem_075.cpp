#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    const int LIMIT = 1500000;
    vector<int> cnt(LIMIT + 1, 0);

    for (int m = 2; 2LL * m * (m + 1) <= LIMIT; m++) {
        for (int n = 1; n < m; n++) {
            if (((m - n) & 1) == 0) continue;
            if (std::gcd(m, n) != 1) continue;

            int p0 = 2 * m * (m + n);
            for (int p = p0; p <= LIMIT; p += p0) cnt[p]++;
        }
    }

    int ans = 0;
    for (int p = 1; p <= LIMIT; p++) if (cnt[p] == 1) ans++;

    cout << ans << "\n"; // 161667
    return 0;
}
