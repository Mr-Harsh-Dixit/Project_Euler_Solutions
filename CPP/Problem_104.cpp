#include <iostream>
#include <cmath>
using namespace std;

static const long long MOD = 1000000000LL;
static const int TARGET_MASK = (1 << 10) - 2; // bits 1..9 set

static inline bool isPandigital1to9(int x) {
    if (x < 100000000) return false;
    int mask = 0;
    for (int i = 0; i < 9; i++) {
        int d = x % 10;
        if (d == 0) return false;
        int bit = 1 << d;
        if (mask & bit) return false;
        mask |= bit;
        x /= 10;
    }
    return mask == TARGET_MASK;
}

static inline int first9DigitsFib(long long n, long double logphi, long double logsqrt5) {
    long double x = n * logphi - logsqrt5;
    long double frac = x - floorl(x);
    long double val = powl(10.0L, frac + 8.0L);
    return (int)val;
}

int main() {
    long double phi = (1.0L + sqrtl(5.0L)) / 2.0L;
    long double logphi = log10l(phi);
    long double logsqrt5 = log10l(5.0L) / 2.0L;

    long long a = 1, b = 1; // F1, F2 mod MOD
    long long n = 2;

    while (true) {
        n++;
        long long c = a + b;
        if (c >= MOD) c %= MOD;
        a = b;
        b = c;

        if (isPandigital1to9((int)b)) {
            int lead = first9DigitsFib(n, logphi, logsqrt5);
            if (isPandigital1to9(lead)) {
                cout << n << "\n"; // 329468
                return 0;
            }
        }
    }
}
