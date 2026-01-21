#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int f = 3; 1LL * f * f <= n; f += 2) {
        if (n % f == 0) return false;
    }
    return true;
}

int main() {
    string s = "7654321"; // start from largest permutation

    do {
        int num = 0;
        for (char c : s) num = num * 10 + (c - '0');

        if (isPrime(num)) {
            cout << num << "\n"; // 7652413
            return 0;
        }
    } while (prev_permutation(s.begin(), s.end()));

    return 0;
}
