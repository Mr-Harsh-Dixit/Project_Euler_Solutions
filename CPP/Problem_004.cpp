#include <iostream>
using namespace std;

static bool isPalindrome(int x) {
    int orig = x, rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev == orig;
}

int main() {
    int best = 0;

    for (int a = 999; a >= 100; --a) {
        int bStart, bStep;
        if (a % 11 == 0) {
            bStart = 999;
            bStep = 1;
        } else {
            bStart = 990;
            bStep = 11;
        }

        for (int b = bStart; b >= a; b -= bStep) {
            int prod = a * b;
            if (prod <= best) break;
            if (isPalindrome(prod)) best = prod;
        }
    }

    cout << best << "\n"; // 906609
    return 0;
}
