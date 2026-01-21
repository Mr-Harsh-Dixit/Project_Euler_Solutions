#include <iostream>
#include <cmath>
using namespace std;

static bool isPent(long long x) {
    long long disc = 1 + 24 * x;
    long long s = (long long) llround(sqrt((long double)disc));
    if (s * s != disc) return false;
    return (1 + s) % 6 == 0;
}

int main() {
    long long n = 144;
    while (true) {
        long long h = n * (2 * n - 1); // hexagonal
        if (isPent(h)) {
            cout << h << "\n"; // 1533776805
            break;
        }
        ++n;
    }
    return 0;
}
