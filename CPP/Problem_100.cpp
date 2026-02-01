#include <iostream>
using namespace std;

int main() {
    const long long LIMIT = 1000000000000LL;

    long long x = 41, y = 29; // n=21, b=15

    while ((x + 1) / 2 <= LIMIT) {
        long long xNew = 3*x + 4*y;
        long long yNew = 2*x + 3*y;
        x = xNew;
        y = yNew;
    }

    long long b = (y + 1) / 2;
    cout << b << "\n"; // 756872327473
    return 0;
}
