#include <iostream>
#include <vector>
#include <queue>
#include <string>
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

static bool isTruncatable(int p, const vector<char>& isPrime) {
    if (p < 10) return false;

    int x = p;
    while (x > 0) {
        if (!isPrime[x]) return false;
        x /= 10;
    }

    string s = to_string(p);
    for (int i = 0; i < (int)s.size(); ++i) {
        int v = stoi(s.substr(i));
        if (!isPrime[v]) return false;
    }
    return true;
}

int main() {
    const int LIMIT = 1'000'000;
    auto isPrime = sieve(LIMIT);

    queue<int> q;
    q.push(2); q.push(3); q.push(5); q.push(7);

    vector<int> found;
    int digits[4] = {1, 3, 7, 9};

    while ((int)found.size() < 11) {
        int n = q.front(); q.pop();

        for (int d : digits) {
            int m = n * 10 + d;
            if (m <= LIMIT && isPrime[m]) {
                q.push(m);
                if (isTruncatable(m, isPrime)) found.push_back(m);
            }
        }
    }

    long long sum = 0;
    for (int x : found) sum += x;

    cout << sum << "\n"; // 748317
    return 0;
}
