#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

static inline bool isSquare(long long n) {
    long long r = (long long) llround(floor(sqrt((long double)n)));
    while (r*r < n) r++;
    while (r*r > n) r--;
    return r*r == n;
}

int main() {
    const long long TARGET = 1'000'000;
    long long total = 0;
    int M = 0;

    while (total <= TARGET) {
        M++;
        long long z = M;
        long long zz = z * z;

        for (long long s = 2; s <= 2 * z; s++) {
            if (isSquare(s * s + zz)) {
                long long lo = max(1LL, s - z);
                long long hi = min(z, s / 2);
                if (hi >= lo) total += (hi - lo + 1);
            }
        }
    }

    cout << M << "\n"; // 1818
    return 0;
}
