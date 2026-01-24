#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static void multiplyDigits(vector<int>& digits, int m) {
    int carry = 0;
    for (size_t i = 0; i < digits.size(); i++) {
        int prod = digits[i] * m + carry;
        digits[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry > 0) {
        digits.push_back(carry % 10);
        carry /= 10;
    }
}

static int digitSum(const vector<int>& digits) {
    int s = 0;
    for (int d : digits) s += d;
    return s;
}

int main() {
    int best = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = 1; b < 100; b++) {
            vector<int> digits = {1};
            for (int i = 0; i < b; i++) multiplyDigits(digits, a);
            best = max(best, digitSum(digits));
        }
    }
    cout << best << "\n"; // 972
    return 0;
}
