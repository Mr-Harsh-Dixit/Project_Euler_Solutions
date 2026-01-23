#include <iostream>
#include <array>
#include <cmath>
using namespace std;

static array<uint8_t, 10> signature(int x) {
    array<uint8_t, 10> cnt{};
    while (x > 0) {
        cnt[x % 10]++;
        x /= 10;
    }
    return cnt;
}

int main() {
    for (int n = 1; ; n++) {
        int low = 1;
        for (int i = 1; i < n; i++) low *= 10;

        int high = (int)(( (long long)pow(10, n) - 1 ) / 6);
        // safer integer power:
        int p10 = 1;
        for (int i = 0; i < n; i++) p10 *= 10;
        high = (p10 - 1) / 6;

        for (int x = low; x <= high; x++) {
            auto sig = signature(x);
            bool ok = true;
            for (int k = 2; k <= 6; k++) {
                if (signature(k * x) != sig) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << x << "\n"; // 142857
                return 0;
            }
        }
    }
}
