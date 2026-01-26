#include <iostream>
#include <vector>
#include <array>
using namespace std;

static vector<int> sieve(int limit) {
    vector<char> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL*i*i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= limit; j += i) isPrime[j] = false;
        }
    }
    vector<int> primes;
    primes.reserve(limit / 10);
    for (int i = 2; i <= limit; i++) if (isPrime[i]) primes.push_back(i);
    return primes;
}

static array<int,10> sig(int x) {
    array<int,10> c{};
    c.fill(0);
    while (x) {
        c[x % 10]++;
        x /= 10;
    }
    return c;
}

int main() {
    const int LIMIT = 10'000'000;
    vector<int> primes = sieve(LIMIT);

    long long bestN = 0;
    long long bestNum = 1;
    long long bestDen = 0;

    for (size_t i = 0; i < primes.size(); i++) {
        long long p = primes[i];
        if (p * p >= LIMIT) break;

        for (size_t j = i; j < primes.size(); j++) {
            long long q = primes[j];
            long long n = p * q;
            if (n >= LIMIT) break;

            long long phi = (p - 1) * (q - 1);

            if (sig((int)n) == sig((int)phi)) {
                if (bestDen == 0 || n * bestDen < bestNum * phi) {
                    bestN = n;
                    bestNum = n;
                    bestDen = phi;
                }
            }
        }
    }

    cout << bestN << "\n"; // 8319823
    return 0;
}
