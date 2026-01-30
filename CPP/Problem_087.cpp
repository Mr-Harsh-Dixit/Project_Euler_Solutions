#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
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

int main() {
    const int LIMIT = 50'000'000;
    auto primes = sieve(7071);

    vector<int> sq, cube, four;
    for (int p : primes) {
        long long p2 = 1LL * p * p;
        if (p2 < LIMIT) sq.push_back((int)p2);

        long long p3 = p2 * p;
        if (p3 < LIMIT) cube.push_back((int)p3);

        long long p4 = p2 * p2;
        if (p4 < LIMIT) four.push_back((int)p4);
    }

    sort(sq.begin(), sq.end());
    sort(cube.begin(), cube.end());
    sort(four.begin(), four.end());

    vector<uint8_t> seen(LIMIT, 0);

    for (int f : four) {
        for (int c : cube) {
            int fc = f + c;
            if (fc >= LIMIT) break;
            for (int s : sq) {
                int v = fc + s;
                if (v >= LIMIT) break;
                seen[v] = 1;
            }
        }
    }

    long long ans = 0;
    for (auto x : seen) ans += x;
    cout << ans << "\n"; // 1097343
    return 0;
}
