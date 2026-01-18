#include <iostream>
#include <vector>
#include <string>
using namespace std;

static vector<char> sieve(int limit) {
    vector<char> isPrime(limit, 1);
    if (limit > 0) isPrime[0] = 0;
    if (limit > 1) isPrime[1] = 0;

    for (int p = 2; 1LL * p * p < limit; ++p) {
        if (isPrime[p]) {
            for (long long x = 1LL * p * p; x < limit; x += p) {
                isPrime[(int)x] = 0;
            }
        }
    }
    return isPrime;
}

static vector<int> rotations(int n) {
    string s = to_string(n);
    vector<int> rots;
    rots.reserve(s.size());
    for (int i = 0; i < (int)s.size(); ++i) {
        string t = s.substr(i) + s.substr(0, i);
        rots.push_back(stoi(t));
    }
    return rots;
}

static bool hasBadDigit(const string& s) {
    for (char c : s) {
        if (c=='0' || c=='2' || c=='4' || c=='5' || c=='6' || c=='8') return true;
    }
    return false;
}

int main() {
    const int LIMIT = 1'000'000;
    vector<char> isPrime = sieve(LIMIT);
    vector<char> processed(LIMIT, 0);

    int total = 0;

    for (int p = 2; p < LIMIT; ++p) {
        if (!isPrime[p] || processed[p]) continue;

        vector<int> rots = rotations(p);
        for (int r : rots) if (r < LIMIT) processed[r] = 1;

        string s = to_string(p);
        if (s.size() > 1 && hasBadDigit(s)) continue;

        bool ok = true;
        for (int r : rots) {
            if (r >= LIMIT || !isPrime[r]) { ok = false; break; }
        }

        if (ok) {
            // count distinct rotations
            // small count (<=6), so O(k^2) uniqueness check is fine
            int add = 0;
            for (int i = 0; i < (int)rots.size(); ++i) {
                bool seen = false;
                for (int j = 0; j < i; ++j) {
                    if (rots[i] == rots[j]) { seen = true; break; }
                }
                if (!seen) add++;
            }
            total += add;
        }
    }

    cout << total << "\n"; // 55
    return 0;
}
