#include <iostream>
using namespace std;

static long long countDivisors(long long x) {
    long long total = 1;

    int exp = 0;
    while (x % 2 == 0) {
        x /= 2;
        exp++;
    }
    if (exp) total *= (exp + 1);

    for (long long p = 3; p * p <= x; p += 2) {
        exp = 0;
        while (x % p == 0) {
            x /= p;
            exp++;
        }
        if (exp) total *= (exp + 1);
    }

    if (x > 1) total *= 2; // remaining prime factor

    return total;
}

int main() {
    const long long threshold = 500;
    long long n = 1;

    while (true) {
        long long a, b;
        if (n % 2 == 0) {
            a = n / 2;
            b = n + 1;
        } else {
            a = n;
            b = (n + 1) / 2;
        }

        if (countDivisors(a) * countDivisors(b) > threshold) {
            cout << (n * (n + 1) / 2) << "\n"; // 76576500
            break;
        }

        n++;
    }

    return 0;
}
