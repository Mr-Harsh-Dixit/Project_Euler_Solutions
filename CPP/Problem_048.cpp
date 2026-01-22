#include <iostream>
#include <cstdint>
#include <iomanip>
using namespace std;

static uint64_t mulMod(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t res = 0;
    a %= mod;
    while (b) {
        if (b & 1) {
            res += a;
            if (res >= mod) res -= mod;
        }
        a <<= 1;
        if (a >= mod) a -= mod;
        b >>= 1;
    }
    return res;
}

static uint64_t modPow(uint64_t a, uint64_t e, uint64_t mod) {
    uint64_t res = 1 % mod;
    a %= mod;
    while (e) {
        if (e & 1) res = mulMod(res, a, mod);
        a = mulMod(a, a, mod);
        e >>= 1;
    }
    return res;
}

int main() {
    const uint64_t MOD = 10000000000ULL; // 1e10
    uint64_t total = 0;

    for (uint64_t i = 1; i <= 1000; ++i) {
        total = (total + modPow(i, i, MOD)) % MOD;
    }

    cout << setw(10) << setfill('0') << total << "\n";
    return 0;
}
