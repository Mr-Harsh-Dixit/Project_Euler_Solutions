#include <iostream>
using namespace std;

static bool isBouncy(int n) {
    bool inc = true, dec = true;
    int last = n % 10;
    n /= 10;

    while (n > 0) {
        int d = n % 10;
        if (d < last) inc = false;
        if (d > last) dec = false;
        last = d;
        n /= 10;

        if (!inc && !dec) return true;
    }
    return false;
}

int main() {
    int bouncy = 0;
    int n = 1;
    while (true) {
        n++;
        if (n >= 100 && isBouncy(n)) bouncy++;
        if ((long long)bouncy * 100 == (long long)n * 99) {
            cout << n << "\n"; // 1587000
            break;
        }
    }
    return 0;
}
