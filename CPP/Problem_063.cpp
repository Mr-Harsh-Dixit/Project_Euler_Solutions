#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int total = 0;
    for (int n = 1;; n++) {
        for (int a = 1; a <= 9; a++) {
            int digits = (int)floor(n * log10((double)a)) + 1;
            if (digits == n) total++;
        }
        int maxDigits = (int)floor(n * log10(9.0)) + 1;
        if (maxDigits < n) break;
    }
    cout << total << "\n"; // 49
    return 0;
}
