#include <iostream>
#include <vector>
using namespace std;

static void digits3(int n, int &a, int &b, int &c) {
    a = n / 100;
    b = (n / 10) % 10;
    c = n % 10;
}

int main() {
    vector<int> primes = {17, 13, 11, 7, 5, 3, 2};
    long long total = 0;

    auto dfs = [&](auto&& self, int step, int usedMask, vector<int>& suffix) -> void {
        // suffix holds current digits from some d_k..d10, growing left
        if (step == (int)primes.size() - 1) {
            // built d2..d10, pick d1
            for (int d = 0; d <= 9; ++d) {
                if (!(usedMask & (1 << d))) {
                    long long num = d;
                    for (int x : suffix) num = num * 10 + x;
                    total += num;
                    return;
                }
            }
            return;
        }

        int prime = primes[step + 1];
        int a = suffix[0], b = suffix[1];

        for (int d = 0; d <= 9; ++d) {
            if (usedMask & (1 << d)) continue;
            int triple = 100 * d + 10 * a + b;
            if (triple % prime == 0) {
                suffix.insert(suffix.begin(), d);
                self(self, step + 1, usedMask | (1 << d), suffix);
                suffix.erase(suffix.begin());
            }
        }
    };

    // Seed with d8d9d10 divisible by 17 (leading zero allowed)
    for (int n = 0; n < 1000; n += 17) {
        int a, b, c;
        digits3(n, a, b, c);
        if (a == b || b == c || a == c) continue;

        int used = (1 << a) | (1 << b) | (1 << c);
        vector<int> suffix = {a, b, c};
        dfs(dfs, 0, used, suffix);
    }

    cout << total << "\n"; // 16695334890
    return 0;
}
