#include <iostream>
#include <utility>
using namespace std;

static inline pair<long long,long long> step(long long x, long long y) {
    // multiply (x + y*sqrt(12)) by (7 + 2*sqrt(12))
    return {7*x + 24*y, 2*x + 7*y};
}

int main() {
    const long long LIMIT = 1'000'000'000LL;
    long long total = 0;

    // Family 1: x = 3a - 1 (a,a,a+1), seed (14,4)
    {
        long long x = 14, y = 4;
        while (true) {
            long long a = (x + 1) / 3;
            long long p = 3*a + 1;
            if (p > LIMIT) break;
            total += p;
            auto nxt = step(x, y);
            x = nxt.first; y = nxt.second;
        }
    }

    // Family 2: x = 3a + 1 (a,a,a-1), seed (52,15)
    {
        long long x = 52, y = 15;
        while (true) {
            long long a = (x - 1) / 3;
            long long p = 3*a - 1;
            if (p > LIMIT) break;
            total += p;
            auto nxt = step(x, y);
            x = nxt.first; y = nxt.second;
        }
    }

    cout << total << "\n"; // 518408346
    return 0;
}
