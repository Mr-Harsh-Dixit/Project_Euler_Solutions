#include <iostream>
using namespace std;

int main() {
    long long n = 100;
    long long sum = n * (n + 1) / 2;
    long long sumSquares = n * (n + 1) * (2 * n + 1) / 6;

    cout << (sum * sum - sumSquares) << "\n"; // 25164150
    return 0;
}
