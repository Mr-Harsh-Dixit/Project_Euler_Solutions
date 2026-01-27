#include <iostream>
#include <numeric>
using namespace std;

int main() {
    const int LIMIT = 12000;
    long long count = 0;

    for (int d = 2; d <= LIMIT; d++) {
        int n_start = d / 3 + 1;
        int n_end = (d - 1) / 2;
        for (int n = n_start; n <= n_end; n++) {
            if (std::gcd(n, d) == 1) count++;
        }
    }

    cout << count << "\n"; // 7295372
    return 0;
}
