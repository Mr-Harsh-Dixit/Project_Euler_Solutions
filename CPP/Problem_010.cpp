#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    const int limit = 2'000'000;
    if (limit <= 2) {
        cout << 0 << "\n";
        return 0;
    }

    // index i represents number (2*i + 3)
    int size = (limit - 1) / 2;
    vector<char> isPrime(size, 1);

    int root = (int)std::sqrt(limit - 1);
    int maxI = (root - 3) / 2;

    for (int i = 0; i <= maxI; ++i) {
        if (isPrime[i]) {
            int p = 2 * i + 3;
            long long start = (1LL * p * p - 3) / 2;
            for (long long j = start; j < size; j += p) {
                isPrime[(int)j] = 0;
            }
        }
    }

    long long sum = 2; // include 2
    for (int i = 0; i < size; ++i) {
        if (isPrime[i]) sum += (2LL * i + 3);
    }

    cout << sum << "\n"; // 142913828922
    return 0;
}
