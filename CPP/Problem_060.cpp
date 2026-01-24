#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

static long long mod_pow(long long a, long long e, long long mod) {
    long long res = 1 % mod;
    a %= mod;
    while (e) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

static bool isPrimeMR(long long n) {
    if (n < 2) return false;
    static int smalls[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int p : smalls) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }

    long long d = n - 1;
    int s = 0;
    while ((d & 1LL) == 0) { d >>= 1; s++; }

    static int bases[] = {2,3,5,7,11};
    for (int a : bases) {
        if (a % n == 0) continue;
        long long x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) {
            x = (x * x) % n;
            if (x == n - 1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}

static vector<int> sieve(int n) {
    vector<bool> isp(n + 1, true);
    isp[0] = isp[1] = false;
    for (int i = 2; 1LL*i*i <= n; i++) if (isp[i])
        for (int j = i*i; j <= n; j += i) isp[j] = false;
    vector<int> ps;
    for (int i = 2; i <= n; i++) if (isp[i]) ps.push_back(i);
    return ps;
}

static int digits10(int x) {
    if (x < 10) return 1;
    if (x < 100) return 2;
    if (x < 1000) return 3;
    if (x < 10000) return 4;
    return 5;
}

int main() {
    const int LIMIT = 10000;
    vector<int> primes = sieve(LIMIT);
    vector<int> ps;
    ps.reserve(primes.size());
    for (int p : primes) if (p != 2 && p != 5) ps.push_back(p);

    long long pow10[6] = {1,10,100,1000,10000,100000};

    unordered_map<long long, bool> primeCache;
    primeCache.reserve(200000);

    auto isPrimeCached = [&](long long x)->bool{
        auto it = primeCache.find(x);
        if (it != primeCache.end()) return it->second;
        bool v = isPrimeMR(x);
        primeCache.emplace(x, v);
        return v;
    };

    auto concat = [&](int a, int b)->long long{
        return (long long)a * pow10[digits10(b)] + b;
    };

    auto compatible = [&](int a, int b)->bool{
        return isPrimeCached(concat(a,b)) && isPrimeCached(concat(b,a));
    };

    // adjacency forward lists
    unordered_map<int, vector<int>> adj;
    adj.reserve(ps.size()*2);
    for (int p : ps) adj[p] = {};

    for (size_t i = 0; i < ps.size(); i++) {
        int p = ps[i];
        for (size_t j = i + 1; j < ps.size(); j++) {
            int q = ps[j];
            if (compatible(p,q)) adj[p].push_back(q);
        }
    }

    auto intersect = [](const vector<int>& a, size_t aStart, const vector<int>& b)->vector<int>{
        vector<int> out;
        size_t i = aStart, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) { out.push_back(a[i]); i++; j++; }
            else if (a[i] < b[j]) i++;
            else j++;
        }
        return out;
    };

    long long bestSum = (1LL<<62);
    vector<int> bestSet;

    function<void(vector<int>&, const vector<int>&, long long)> dfs =
        [&](vector<int>& chosen, const vector<int>& cand, long long ssum) {

        int k = (int)chosen.size();
        if (k == 5) {
            if (ssum < bestSum) { bestSum = ssum; bestSet = chosen; }
            return;
        }
        if (cand.empty() || ssum >= bestSum) return;

        int need = 5 - k;
        for (size_t idx = 0; idx < cand.size(); idx++) {
            int v = cand[idx];
            if (ssum + 1LL * v * need >= bestSum) break;

            vector<int> newCand = intersect(cand, idx + 1, adj[v]);
            chosen.push_back(v);
            dfs(chosen, newCand, ssum + v);
            chosen.pop_back();
        }
    };

    for (int p : ps) {
        if (1LL * p * 5 >= bestSum) break;
        vector<int> chosen = {p};
        dfs(chosen, adj[p], p);
    }

    cout << bestSum << "\n"; // 26033
    return 0;
}
