#include <iostream>
using namespace std;

unsigned long long nCr(int n, int r) {
    r = min(r, n - r);
    unsigned long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i; // exact division each step
    }
    return res;
}

int main() {
    cout << nCr(40, 20) << "\n"; // 137846528820
    return 0;
}
