#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int limit = 1'000'000;
    vector<int> cache(limit + 1, 0);
    cache[1] = 1;

    int bestStart = 1;
    int bestLen = 1;

    for (int start = 2; start < limit; ++start) {
        long long n = start;
        vector<long long> path;
        path.reserve(200);

        while (n != 1 && (n > limit || cache[(int)n] == 0)) {
            path.push_back(n);
            if ((n & 1LL) == 0) n >>= 1;
            else n = 3 * n + 1;
        }

        int total = (n == 1) ? 1 : cache[(int)n];

        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            total++;
            long long x = *it;
            if (x <= limit) cache[(int)x] = total;
        }

        if (cache[start] > bestLen) {
            bestLen = cache[start];
            bestStart = start;
        }
    }

    cout << bestStart << "\n"; // 837799
    return 0;
}
