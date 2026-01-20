#include <iostream>
#include <vector>
using namespace std;

static int gcdint(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    const int LIMIT = 1000;
    vector<int> cnt(LIMIT + 1, 0);

    for (int m = 2; 2 * m * (m + 1) <= LIMIT; ++m) {
        for (int n = 1; n < m; ++n) {
            if (((m - n) & 1) == 0) continue;      // must be odd difference
            if (gcdint(m, n) != 1) continue;       // coprime

            int p0 = 2 * m * (m + n);
            for (int p = p0; p <= LIMIT; p += p0) {
                cnt[p]++;
            }
        }
    }

    int bestP = 0, bestCnt = 0;
    for (int p = 1; p <= LIMIT; ++p) {
        if (cnt[p] > bestCnt) {
            bestCnt = cnt[p];
            bestP = p;
        }
    }

    cout << bestP << "\n"; // 840
    return 0;
}
