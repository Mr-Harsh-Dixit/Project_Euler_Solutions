#include <iostream>
#include <vector>
using namespace std;

static vector<char> sieve(int limit) {
    vector<char> isPrime(limit + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; 1LL * p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (long long x = 1LL * p * p; x <= limit; x += p) {
                isPrime[(int)x] = 0;
            }
        }
    }
    return isPrime;
}

int main() {
    const int LIMIT = 2'000'000;
    auto isPrime = sieve(LIMIT);

    vector<int> primesB;
    for (int b = 2; b <= 1000; ++b) if (isPrime[b]) primesB.push_back(b);

    int bestLen = 0;
    int bestProd = 0;

    for (int b : primesB) {
        for (int a = -999; a <= 999; ++a) {
            int v1 = 1 + a + b;
            if (v1 <= 1 || !isPrime[v1]) continue;

            int n = 0;
            while (true) {
                long long val = 1LL * n * n + 1LL * a * n + b;
                if (val <= 1 || val > LIMIT || !isPrime[(int)val]) break;
                n++;
            }

            if (n > bestLen) {
                bestLen = n;
                bestProd = a * b;
            }
        }
    }

    cout << bestProd << "\n"; // -59231
    return 0;
}
