#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<char> sieve(int limit) {
    vector<char> isPrime(limit + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; 1LL * p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (long long x = 1LL * p * p; x <= limit; x += p)
                isPrime[(int)x] = 0;
        }
    }
    return isPrime;
}

static bool isSquare(long long x) {
    long long s = (long long) llround(sqrt((long double)x));
    while (s * s < x) ++s;
    while (s * s > x) --s;
    return s * s == x;
}

int main() {
    const int LIMIT = 100000;
    auto isPrime = sieve(LIMIT);

    vector<int> primes;
    for (int i = 2; i <= LIMIT; ++i) if (isPrime[i]) primes.push_back(i);

    for (int n = 9;; n += 2) {
        if (n <= LIMIT && isPrime[n]) continue; // skip primes

        bool ok = false;
        for (int p : primes) {
            if (p >= n) break;
            int r = n - p;
            if ((r % 2 == 0) && isSquare(r / 2)) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << n << "\n"; // 5777
            break;
        }
    }

    return 0;
}
