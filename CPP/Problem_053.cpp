#include <iostream>
using namespace std;

int main() {
    const long long LIMIT = 1'000'000;
    const int N = 100;
    long long total = 0;

    for (int n = 1; n <= N; n++) {
        long long c = 1; // C(n,0)
        for (int r = 1; r <= n / 2; r++) {
            c = (c * (n - r + 1)) / r; // exact integer division
            if (c > LIMIT) {
                total += (n - 2LL * r + 1);
                break;
            }
        }
    }

    cout << total << "\n"; // 4075
    return 0;
}
