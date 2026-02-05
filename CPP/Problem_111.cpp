#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;

using u64  = unsigned long long;

static u64 mod_mul(u64 a, u64 b, u64 mod) {
    a %= mod;
    b %= mod;
    u64 result = 0;
    while (b > 0) {
        if (b & 1) result = (result + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}

static u64 mod_pow(u64 a, u64 d, u64 mod) {
    u64 r = 1;
    while (d) {
        if (d & 1) r = mod_mul(r, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return r;
}

static bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}) {
        if (n % p == 0) return n == p;
    }

    u64 d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }

    auto witness = [&](u64 a) {
        if (a % n == 0) return true;
        u64 x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) return true;
        for (u64 i = 1; i < s; i++) {
            x = mod_mul(x, x, n);
            if (x == n - 1) return true;
        }
        return false;
    };

    // deterministic bases for 64-bit
    for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) {
        if (!witness(a)) return false;
    }
    return true;
}

static void genCandidates(int n, int d, int r,
                          const vector<int>& choices,
                          long long &sumOut, int &cntOut) {
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);

    vector<int> pick(r);
    // combinations of positions via bitmask approach
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    vector<int> comb;
    // generate combinations recursively (n is 10, r is tiny)
    function<void(int,int,vector<int>&)> choosePos = [&](int start, int left, vector<int>& cur){
        if (left == 0) {
            // for these positions, iterate assignments (choices^r)
            int base = (int)choices.size();
            int totalAssign = 1;
            for (int i = 0; i < r; i++) totalAssign *= base;

            vector<int> arr(n, d);

            for (int t = 0; t < totalAssign; t++) {
                int x = t;
                // build number
                fill(arr.begin(), arr.end(), d);
                for (int i = 0; i < r; i++) {
                    int dig = choices[x % base];
                    x /= base;
                    arr[cur[i]] = dig;
                }

                if (arr[0] == 0) continue;
                int last = arr[n-1];
                if (last % 2 == 0 || last == 5) continue;

                u64 num = 0;
                for (int v : arr) num = num * 10 + (u64)v;

                if (isPrime(num)) {
                    sumOut += (long long)num;
                    cntOut++;
                }
            }
            return;
        }
        for (int i = start; i <= n - left; i++) {
            cur.push_back(i);
            choosePos(i + 1, left - 1, cur);
            cur.pop_back();
        }
    };

    vector<int> cur;
    choosePos(0, r, cur);
}

int main() {
    const int n = 10;
    long long total = 0;

    for (int d = 0; d <= 9; d++) {
        vector<int> choices;
        for (int x = 0; x <= 9; x++) if (x != d) choices.push_back(x);

        for (int r = 0; r <= n; r++) {
            long long sumD = 0;
            int cnt = 0;
            genCandidates(n, d, r, choices, sumD, cnt);
            if (cnt > 0) {
                total += sumD;
                break;
            }
        }
    }

    cout << total << "\n"; // 612407567715
    return 0;
}
