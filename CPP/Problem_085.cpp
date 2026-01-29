#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    const long long TARGET = 2'000'000;
    long long bestDiff = (1LL<<62);
    long long bestArea = 0;

    for (int m = 1; m <= 2000; m++) {
        long long tm = 1LL * m * (m + 1) / 2;
        double x = (double)TARGET / (double)tm;

        int n0 = (int)((sqrt(1.0 + 8.0 * x) - 1.0) / 2.0);

        for (int n : {n0, n0 + 1}) {
            if (n <= 0) continue;
            long long tn = 1LL * n * (n + 1) / 2;
            long long rect = tm * tn;
            long long diff = llabs(rect - TARGET);
            if (diff < bestDiff) {
                bestDiff = diff;
                bestArea = 1LL * m * n;
            }
        }
    }

    cout << bestArea << "\n"; // 2772 (36*77)
    return 0;
}
