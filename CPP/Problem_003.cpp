#include <iostream>
using namespace std;

int main() {
    long long n = 600851475143LL;
    long long maxFactor = 1;

    while (n % 2 == 0) {
        maxFactor = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxFactor = i;
            n /= i;
        }
    }

    if (n > 1)
        maxFactor = n;

    cout << maxFactor << "\n"; // 6857
    return 0;
}
