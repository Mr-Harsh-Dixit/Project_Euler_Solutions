#include <iostream>
#include <vector>
#include <set>
using namespace std;

static vector<int> sievePrimes(int n) {
    vector<char> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int x = p * p; x <= n; x += p) isPrime[x] = 0;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) if (isPrime[i]) primes.push_back(i);
    return primes;
}

int main() {
    const int MAXA = 100, MAXB = 100;
    vector<int> primes = sievePrimes(MAXA);

    // signature = vector of exponents for each prime (scaled by b)
    set<vector<int>> sigs;

    for (int a = 2; a <= MAXA; ++a) {
        vector<int> baseExp(primes.size(), 0);
        int x = a;

        for (int i = 0; i < (int)primes.size(); ++i) {
            int p = primes[i];
            while (x % p == 0) {
                baseExp[i]++;
                x /= p;
            }
        }

        for (int b = 2; b <= MAXB; ++b) {
            vector<int> sig = baseExp;
            for (int i = 0; i < (int)sig.size(); ++i) sig[i] *= b;
            sigs.insert(sig);
        }
    }

    cout << sigs.size() << "\n"; // 9183
    return 0;
}
