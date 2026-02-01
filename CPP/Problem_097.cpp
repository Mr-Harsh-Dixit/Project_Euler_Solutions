#include <iostream>
#include <iomanip>
using namespace std;

long long mulmod(long long a, long long b, long long mod) {
    return (long long)(((__int64)a * b) % mod);
}

long long modPow(long long base, long long exp, long long mod) {
    long long res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = mulmod(res, base, mod);
        base = mulmod(base, base, mod);
        exp >>= 1;
    }
    return res;
}

int main() {
    const long long MOD = 10000000000LL; // 1e10
    long long p = modPow(2, 7830457, MOD);
    long long ans = ((mulmod(28433, p, MOD) + 1) % MOD);

    cout << setw(10) << setfill('0') << ans << "\n"; // 8739992577
    return 0;
}
