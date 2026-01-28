#include <iostream>
#include <vector>
using namespace std;

static vector<int> sieve(int n) {
    vector<char> isPrime(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes.push_back(i);
    return primes;
}

int main() {
    const int THRESH = 5000;
    int n = 2;

    while (true) {
        vector<int> primes = sieve(n);
        vector<int> ways(n + 1, 0);
        ways[0] = 1;

        for (int p : primes) {
            for (int s = p; s <= n; s++) {
                ways[s] += ways[s - p];
            }
        }

        if (ways[n] > THRESH) {
            cout << n << "\n"; // 71
            return 0;
        }
        n++;
    }
}
