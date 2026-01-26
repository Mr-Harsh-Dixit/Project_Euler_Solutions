#include <iostream>
using namespace std;

static bool isPrime(int x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int i = 3; 1LL*i*i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

static int nextPrime(int p) {
    int x = p + 1;
    while (!isPrime(x)) x++;
    return x;
}

int main() {
    const int LIMIT = 1'000'000;
    long long n = 1;
    int p = 2;

    while (n * p <= LIMIT) {
        n *= p;
        p = nextPrime(p);
    }

    cout << n << "\n"; // 510510
    return 0;
}
