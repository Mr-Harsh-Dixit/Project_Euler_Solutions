#include <iostream>
using namespace std;

int main() {
    const int N = 1001;
    long long total = 1;

    for (long long n = 3; n <= N; n += 2) {
        total += 4 * n * n - 6 * (n - 1);
    }

    cout << total << "\n"; // 669171001
    return 0;
}
