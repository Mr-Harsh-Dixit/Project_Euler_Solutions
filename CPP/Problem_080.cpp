#include <iostream>
#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

// Integer square root: floor(sqrt(n)) for big integers using Newton's method
static cpp_int isqrt(const cpp_int& n) {
    if (n == 0) return 0;

    // Initial guess: 1 << ceil(bitlen/2)
    unsigned int bitlen = boost::multiprecision::msb(n) + 1;
    cpp_int x = cpp_int(1) << ((bitlen + 1) / 2);

    while (true) {
        cpp_int y = (x + n / x) >> 1;
        if (y >= x) return x; // converged downward to floor sqrt
        x = y;
    }
}

static bool is_square_int(int n) {
    int r = (int)std::sqrt((double)n);
    return r * r == n;
}

static cpp_int pow10(int exp) {
    cpp_int r = 1;
    for (int i = 0; i < exp; i++) r *= 10;
    return r;
}

int main() {
    cpp_int scale = pow10(200); // 10^200
    long long total = 0;

    for (int n = 1; n <= 100; n++) {
        if (is_square_int(n)) continue;

        cpp_int big = cpp_int(n) * scale;
        cpp_int root = isqrt(big);

        std::string s = root.convert_to<std::string>();

        // For n<=100 and non-square: sqrt(n) in (1,10), so root has 101 digits.
        // Still, to be safe, ensure we have at least 100 digits.
        if ((int)s.size() < 100) {
            // pad with leading zeros if ever needed (won't happen here)
            s = std::string(100 - s.size(), '0') + s;
        }

        for (int i = 0; i < 100; i++) {
            total += (s[i] - '0');
        }
    }

    cout << total << "\n"; // 40886
    return 0;
}
