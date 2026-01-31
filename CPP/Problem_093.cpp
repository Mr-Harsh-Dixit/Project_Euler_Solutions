#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>
#include <functional>
#include <numeric>
#include <cmath>
using namespace std;

struct Frac {
    long long n, d; // n/d reduced, d>0
    Frac(long long nn=0, long long dd=1) {
        if (dd == 0) throw runtime_error("div0");
        if (dd < 0) nn = -nn, dd = -dd;
        long long g = std::gcd(llabs(nn), dd);
        n = nn / g; d = dd / g;
    }
};

static inline Frac addF(const Frac& a, const Frac& b){ return Frac(a.n*b.d + b.n*a.d, a.d*b.d); }
static inline Frac subF(const Frac& a, const Frac& b){ return Frac(a.n*b.d - b.n*a.d, a.d*b.d); }
static inline Frac mulF(const Frac& a, const Frac& b){ return Frac(a.n*b.n, a.d*b.d); }
static inline Frac divF(const Frac& a, const Frac& b){
    if (b.n == 0) throw runtime_error("div0");
    return Frac(a.n*b.d, a.d*b.n);
}

struct FracHash {
    size_t operator()(Frac const& f) const noexcept {
        return std::hash<long long>()((f.n<<1) ^ f.d);
    }
};
struct FracEq {
    bool operator()(Frac const& a, Frac const& b) const noexcept {
        return a.n==b.n && a.d==b.d;
    }
};

unordered_set<Frac, FracHash, FracEq> allValues(const vector<Frac>& nums) {
    if (nums.size() == 1) {
        return unordered_set<Frac, FracHash, FracEq>{nums[0]};
    }

    unordered_set<Frac, FracHash, FracEq> out;
    int L = (int)nums.size();

    for (int i=0;i<L;i++){
        for (int j=i+1;j<L;j++){
            Frac a = nums[i], b = nums[j];
            vector<Frac> rest;
            rest.reserve(L-1);
            for (int k=0;k<L;k++) if (k!=i && k!=j) rest.push_back(nums[k]);

            auto merge = [&](Frac v){
                auto next = rest;
                next.push_back(v);
                auto s = allValues(next);
                out.insert(s.begin(), s.end());
            };

            merge(addF(a,b));
            merge(mulF(a,b));
            merge(subF(a,b));
            merge(subF(b,a));
            if (b.n != 0) merge(divF(a,b));
            if (a.n != 0) merge(divF(b,a));
        }
    }
    return out;
}

int main() {
    int bestLen = 0;
    array<int,4> best{};

    for (int a=1;a<=6;a++){
        for (int b=a+1;b<=7;b++){
            for (int c=b+1;c<=8;c++){
                for (int d=c+1;d<=9;d++){
                    vector<Frac> start = {Frac(a),Frac(b),Frac(c),Frac(d)};
                    auto vals = allValues(start);

                    unordered_set<int> ints;
                    for (auto &v : vals) {
                        if (v.d == 1 && v.n > 0 && v.n <= INT_MAX) ints.insert((int)v.n);
                    }
                    int n = 1;
                    while (ints.count(n)) n++;
                    int runLen = n - 1;

                    if (runLen > bestLen) {
                        bestLen = runLen;
                        best = {a,b,c,d};
                    }
                }
            }
        }
    }

    cout << best[0] << best[1] << best[2] << best[3] << "\n"; // 1258
    return 0;
}
