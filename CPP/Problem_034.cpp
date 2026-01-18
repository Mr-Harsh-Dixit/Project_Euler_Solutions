#include <iostream>
using namespace std;

static int factorial(int x) {
    int f = 1;
    for (int i = 2; i <= x; ++i) f *= i;
    return f;
}

int main() {
    int fact[10];
    for (int d = 0; d <= 9; ++d) fact[d] = factorial(d);

    const int limit = 7 * fact[9]; // 2540160

    long long total = 0;
    for (int n = 3; n <= limit; ++n) {
        int s = 0;
        int x = n;
        while (x > 0) {
            s += fact[x % 10];
            x /= 10;
        }
        if (s == n) total += n;
    }

    cout << total << "\n"; // 40730
    return 0;
}
