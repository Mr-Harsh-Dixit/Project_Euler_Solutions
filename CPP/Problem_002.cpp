#include <iostream>
using namespace std;

int main() {
    const long long limit = 4'000'000;
    long long total = 0;
    long long a = 2, b = 8;

    while (a <= limit) {
        total += a;
        long long next = 4 * b + a;
        a = b;
        b = next;
    }

    cout << total << "\n"; // 4613732
    return 0;
}
