#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

static long long pent(long long n) {
    return n * (3 * n - 1) / 2;
}

static bool isPent(long long x) {
    long long disc = 1 + 24 * x;
    long long s = (long long) llround(sqrt((long double)disc));
    if (s * s != disc) return false;
    return (1 + s) % 6 == 0;
}

int main() {
    long long best = numeric_limits<long long>::max();

    for (long long k = 2;; ++k) {
        long long pk = pent(k);

        for (long long j = k - 1; j >= 1; --j) {
            long long pj = pent(j);
            long long d = pk - pj;
            if (d >= best) break;

            if (isPent(d) && isPent(pk + pj)) {
                best = d;
            }
        }

        if (best != numeric_limits<long long>::max()) {
            long long minNextDiff = pent(k) - pent(k - 1);
            if (minNextDiff > best) break;
        }
    }

    cout << best << "\n"; // 5482660
    return 0;
}
