#include <iostream>
using namespace std;

int main() {
    const int S = 1000;
    const int target = S / 2; // k*m*(m+n) = 500

    for (int m = 2; m < 1000; ++m) {
        for (int n = 1; n < m; ++n) {
            int denom = m * (m + n);
            if (denom > target) break;

            if (target % denom == 0) {
                int k = target / denom;
                long long a = 1LL * k * (m * m - n * n);
                long long b = 1LL * k * (2 * m * n);
                long long c = 1LL * k * (m * m + n * n);

                if (a + b + c == S) {
                    cout << (a * b * c) << "\n"; // 31875000
                    return 0;
                }
            }
        }
    }
    return 0;
}
