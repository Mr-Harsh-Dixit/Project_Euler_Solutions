#include <iostream>
using namespace std;

int main() {
    int pow5[10];
    for (int d = 0; d <= 9; ++d) {
        int p = 1;
        for (int i = 0; i < 5; ++i) p *= d;
        pow5[d] = p;
    }

    const int limit = 6 * 59049; // 6 * 9^5 = 354294

    long long total = 0;
    for (int n = 2; n <= limit; ++n) {
        int s = 0;
        int x = n;
        while (x > 0) {
            s += pow5[x % 10];
            x /= 10;
        }
        if (s == n) total += n;
    }

    cout << total << "\n"; // 443839
    return 0;
}
