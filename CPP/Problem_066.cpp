#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Big integer base 1e9 (little-endian)
struct Big {
    static const int BASE = 1000000000;
    vector<int> d;

    Big(long long x = 0) {
        if (x == 0) d = {0};
        else while (x) { d.push_back((int)(x % BASE)); x /= BASE; }
    }

    void trim() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }
};

static int cmp(const Big& a, const Big& b) {
    if (a.d.size() != b.d.size()) return (a.d.size() < b.d.size()) ? -1 : 1;
    for (int i = (int)a.d.size() - 1; i >= 0; --i) {
        if (a.d[i] != b.d[i]) return (a.d[i] < b.d[i]) ? -1 : 1;
    }
    return 0;
}

static Big add(const Big& a, const Big& b) {
    Big r;
    r.d.assign(max(a.d.size(), b.d.size()) + 1, 0);
    long long carry = 0;
    for (size_t i = 0; i < r.d.size(); i++) {
        long long s = carry;
        if (i < a.d.size()) s += a.d[i];
        if (i < b.d.size()) s += b.d[i];
        r.d[i] = (int)(s % Big::BASE);
        carry = s / Big::BASE;
    }
    r.trim();
    return r;
}

static Big mulSmall(const Big& a, long long m) {
    Big r;
    r.d.assign(a.d.size() + 2, 0);
    long long carry = 0;
    for (size_t i = 0; i < a.d.size(); i++) {
        long long cur = carry + 1LL * a.d[i] * m;
        r.d[i] = (int)(cur % Big::BASE);
        carry = cur / Big::BASE;
    }
    size_t idx = a.d.size();
    while (carry) {
        r.d[idx++] = (int)(carry % Big::BASE);
        carry /= Big::BASE;
    }
    r.d.resize(idx);
    r.trim();
    return r;
}

static Big mul(const Big& a, const Big& b) {
    Big r;
    r.d.assign(a.d.size() + b.d.size(), 0);
    for (size_t i = 0; i < a.d.size(); i++) {
        long long carry = 0;
        for (size_t j = 0; j < b.d.size() || carry; j++) {
            long long cur = r.d[i + j] + carry;
            if (j < b.d.size()) cur += 1LL * a.d[i] * b.d[j];
            r.d[i + j] = (int)(cur % Big::BASE);
            carry = cur / Big::BASE;
        }
    }
    r.trim();
    return r;
}

static Big sub(const Big& a, const Big& b) {
    // assume a >= b
    Big r = a;
    long long carry = 0;
    for (size_t i = 0; i < r.d.size(); i++) {
        long long cur = (long long)r.d[i] - carry - (i < b.d.size() ? b.d[i] : 0);
        if (cur < 0) { cur += Big::BASE; carry = 1; }
        else carry = 0;
        r.d[i] = (int)cur;
    }
    r.trim();
    return r;
}

static Big minimalX(int D) {
    int a0 = (int)floor(sqrt((double)D));
    long long m = 0, d = 1, a = a0;

    Big p_m2(0), p_m1(1);
    Big q_m2(1), q_m1(0);

    while (true) {
        Big p = add(mulSmall(p_m1, a), p_m2);
        Big q = add(mulSmall(q_m1, a), q_m2);

        // check p^2 - D q^2 == 1
        Big p2 = mul(p, p);
        Big q2 = mul(q, q);
        Big Dq2 = mulSmall(q2, D);
        Big diff = sub(p2, Dq2);
        if (diff.d.size() == 1 && diff.d[0] == 1) return p;

        p_m2 = p_m1; p_m1 = p;
        q_m2 = q_m1; q_m1 = q;

        m = d * a - m;
        d = (D - m * m) / d;
        a = (a0 + m) / d;
    }
}

int main() {
    int bestD = 0;
    Big bestX(0);

    for (int D = 2; D <= 1000; D++) {
        int a0 = (int)floor(sqrt((double)D));
        if (a0 * 1LL * a0 == D) continue;

        Big x = minimalX(D);
        if (cmp(x, bestX) > 0) {
            bestX = x;
            bestD = D;
        }
    }

    cout << bestD << "\n"; // 661
    return 0;
}
