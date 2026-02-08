#include <bits/stdc++.h>
using namespace std;

static vector<int> sieve(int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= N; i++) {
        if (isPrime[i]) {
            for (long long j = 1LL * i * i; j <= N; j += i) isPrime[(int)j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= N; i++) if (isPrime[i]) primes.push_back(i);
    return primes;
}

int main() {
    const long long THRESH = 10000000000LL; // 1e10
    auto primes = sieve(500000);

    for (int n = 1; n <= (int)primes.size(); n++) {
        if (n & 1) {
            long long p = primes[n - 1];
            if (2LL * n * p > THRESH) {
                cout << n << "\n"; // 21035
                return 0;
            }
        }
    }
    cout << "Need bigger sieve\n";
    return 0;
}
