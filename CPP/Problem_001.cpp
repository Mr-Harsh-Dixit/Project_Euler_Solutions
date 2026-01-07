#include <iostream>
using namespace std;

static long long sumMultiples(int k, int n) {
    long long m = (n - 1) / k;
    return k * m * (m + 1) / 2;
}

int main() {
    const int limit = 1000;
    long long result = sumMultiples(3, limit) + sumMultiples(5, limit) - sumMultiples(15, limit);
    cout << result << endl; // Expected output: 233168
    return 0;
}
