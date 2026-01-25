#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int LIMIT = 10000;
    int count = 0;

    for (int N = 2; N <= LIMIT; N++) {
        int a0 = (int)floor(sqrt((double)N));
        if (a0 * 1LL * a0 == N) continue;

        long long m = 0, d = 1, a = a0;
        int period = 0;

        while (true) {
            m = d * a - m;
            d = (N - m * m) / d;
            a = (a0 + m) / d;
            period++;
            if (a == 2LL * a0) break;
        }

        if (period & 1) count++;
    }

    cout << count << "\n"; // 1322
    return 0;
}
