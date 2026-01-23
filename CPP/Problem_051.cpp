#include <vector>
#include <string>
#include <iostream>

using namespace std;

static vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (isPrime[(int)i]) {
            for (long long j = i * i; j <= n; j += i)
                isPrime[(int)j] = false;
        }
    }
    return isPrime;
}

static int euler51(int limit = 2000000) {
    auto isPrime = sieve(limit);

    for (int p = 2; p <= limit; p++) {
        if (!isPrime[p]) continue;

        string s = to_string(p);
        int L = (int)s.size();

        for (char d = '0'; d <= '9'; d++) {
            vector<int> pos;
            pos.reserve(L);
            for (int i = 0; i < L; i++) {
                if (s[i] == d && i != L - 1) pos.push_back(i);
            }
            int k = (int)pos.size();
            if (k == 0) continue;

            for (int mask = 1; mask < (1 << k); mask++) {
                vector<int> idxs;
                idxs.reserve(k);
                for (int j = 0; j < k; j++)
                    if (mask & (1 << j)) idxs.push_back(pos[j]);

                string pattern = s;
                for (int idx : idxs) pattern[idx] = '*';

                int cnt = 0;
                int smallest = INT_MAX;
                bool leading = (find(idxs.begin(), idxs.end(), 0) != idxs.end());

                for (char r = '0'; r <= '9'; r++) {
                    if (leading && r == '0') continue;

                    string candStr = pattern;
                    for (char &c : candStr)
                        if (c == '*') c = r;

                    int cand = stoi(candStr);
                    if (cand <= limit && isPrime[cand]) {
                        cnt++;
                        smallest = min(smallest, cand);
                        if (cnt > 8) break;
                    }
                }

                if (cnt == 8 && smallest == p) return p;
            }
        }
    }
}

int main() {
    cout << euler51() << "\n"; // 121313
    return 0;
}
