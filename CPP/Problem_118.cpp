#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

using u64 = unsigned long long;

static u64 mod_mul(u64 a, u64 b, u64 mod) {
    u64 res = 0;
    a %= mod;

    while (b) {
        if (b & 1)
            res = (res + a) % mod;

        a = (a << 1) % mod;
        b >>= 1;
    }

    return res;
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

// Deterministic Miller-Rabin for 32-bit-ish range (we're < 1e9)
static bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }

    auto witness = [&](u64 a)->bool{
        if (a % n == 0) return true;
        u64 x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) return true;
        for (u64 i = 1; i < s; i++) {
            x = mod_mul(x, x, n);
            if (x == n - 1) return true;
        }
        return false;
    };

    for (u64 a : {2ULL,3ULL,5ULL,7ULL,11ULL}) {
        if (!witness(a)) return false;
    }
    return true;
}

static const int ALL = (1<<9) - 1;
static vector<vector<int>> primesByMask(ALL+1);

static vector<int> digitsFromMask(int mask) {
    vector<int> d;
    for (int i = 0; i < 9; i++) if (mask & (1<<i)) d.push_back(i+1);
    return d;
}

static vector<int> buildPrimesForMask(int mask) {
    vector<int> digs = digitsFromMask(mask);
    int sum = 0;
    for (int x: digs) sum += x;
    if (sum % 3 == 0 && !(digs.size() == 1 && digs[0] == 3)) return {};

    sort(digs.begin(), digs.end());
    vector<int> used(digs.size(), 0);
    unordered_set<int> res;
    res.reserve(128);

    function<void(int,int)> backtrack = [&](int cur, int depth){
        if (depth == (int)digs.size()) {
            if (digs.size() > 1) {
                int last = cur % 10;
                if (last % 2 == 0 || last == 5) return;
            }
            if (isPrime((u64)cur)) res.insert(cur);
            return;
        }
        for (int i = 0; i < (int)digs.size(); i++) {
            if (used[i]) continue;
            used[i] = 1;
            backtrack(cur*10 + digs[i], depth+1);
            used[i] = 0;
        }
    };

    backtrack(0, 0);
    vector<int> out(res.begin(), res.end());
    sort(out.begin(), out.end());
    return out;
}

// memo: remaining_mask + last_val hashed
struct Key {
    int mask;
    int last;
    bool operator==(Key const& o) const { return mask==o.mask && last==o.last; }
};
struct KeyHash {
    size_t operator()(Key const& k) const {
        return (size_t)k.mask * 1000003u ^ (size_t)k.last;
    }
};

static unordered_map<Key, long long, KeyHash> memo;

static long long dfs(int remaining, int lastVal) {
    if (remaining == 0) return 1;
    Key key{remaining, lastVal};
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;

    long long total = 0;
    for (int sub = remaining; sub; sub = (sub - 1) & remaining) {
        auto &plist = primesByMask[sub];
        if (plist.empty()) continue;
        auto pos = upper_bound(plist.begin(), plist.end(), lastVal);
        for (auto jt = pos; jt != plist.end(); ++jt) {
            total += dfs(remaining ^ sub, *jt);
        }
    }
    memo.emplace(key, total);
    return total;
}

int main() {
    for (int m = 1; m <= ALL; m++) primesByMask[m] = buildPrimesForMask(m);
    cout << dfs(ALL, 0) << "\n"; // 44680
    return 0;
}
