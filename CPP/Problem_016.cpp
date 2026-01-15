#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> digits;
    digits.push_back(1); // number = 1, LSD first

    for (int t = 0; t < 1000; ++t) {
        int carry = 0;
        for (int i = 0; i < (int)digits.size(); ++i) {
            int val = digits[i] * 2 + carry;
            digits[i] = val % 10;
            carry = val / 10;
        }
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    int sum = 0;
    for (int d : digits) sum += d;

    cout << sum << "\n"; // 1366
    return 0;
}
