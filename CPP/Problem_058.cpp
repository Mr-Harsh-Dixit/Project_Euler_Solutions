#include <iostream>
#include <vector>
using namespace std;

static vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes.push_back(i);
    return primes;
}

static bool isPrimeFast(long long n, const vector<int>& primes) {
    if (n < 2) return false;
    for (int p : primes) {
        long long pp = 1LL * p * p;
        if (pp > n) break;
        if (n % p == 0) return n == p;
    }
    return true;
}

int main() {
    auto primes = sieve(30000);

    long long primeCount = 0;
    long long diagTotal = 1;
    int k = 0;

    while (true) {
        k++;
        long long s = 2LL * k + 1;
        long long step = s - 1;
        long long sq = s * s;

        long long c1 = sq - step;
        long long c2 = sq - 2 * step;
        long long c3 = sq - 3 * step;

        if (isPrimeFast(c1, primes)) primeCount++;
        if (isPrimeFast(c2, primes)) primeCount++;
        if (isPrimeFast(c3, primes)) primeCount++;

        diagTotal += 4;

        if (primeCount * 10 < diagTotal) {
            cout << s << "\n"; // 26241
            return 0;
        }
    }
}
