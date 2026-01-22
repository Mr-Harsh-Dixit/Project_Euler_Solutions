#include <iostream>
#include <vector>
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

int main() {
    const int LIMIT = 1000000;
    auto isPrime = sieve(LIMIT);

    vector<int> primes;
    for (int i = 2; i < LIMIT; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }

    vector<long long> pref(primes.size() + 1, 0);
    for (size_t i = 0; i < primes.size(); ++i) {
        pref[i + 1] = pref[i] + primes[i];
    }

    int bestLen = 0;
    int bestPrime = 0;

    int n = (int)primes.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + bestLen + 1; j <= n; ++j) {
            long long sum = pref[j] - pref[i];
            if (sum >= LIMIT) break;
            if (isPrime[(int)sum]) {
                bestLen = j - i;
                bestPrime = (int)sum;
            }
        }
    }

    cout << bestPrime << "\n"; // 997651
    return 0;
}
