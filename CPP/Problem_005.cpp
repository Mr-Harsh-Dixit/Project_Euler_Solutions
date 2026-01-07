#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long result = 1;
    for (int i = 2; i <= 20; ++i) {
        result = lcm(result, i);
    }

    cout << result << "\n"; // 232792560
    return 0;
}
