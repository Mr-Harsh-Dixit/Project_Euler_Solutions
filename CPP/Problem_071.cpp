#include <iostream>
using namespace std;

int main() {
    const int LIMIT = 1'000'000;
    long long best_n = 0, best_d = 1;

    for (long long d = 2; d <= LIMIT; d++) {
        long long n = (3 * d - 1) / 7;
        if (n * best_d > best_n * d) {
            best_n = n;
            best_d = d;
        }
    }

    cout << best_n << "\n"; // 428570
    return 0;
}
