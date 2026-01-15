#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> digits;
    digits.push_back(1); // number = 1, LSD first

    for (int x = 2; x <= 100; ++x) {
        int carry = 0;
        for (int i = 0; i < (int)digits.size(); ++i) {
            int val = digits[i] * x + carry;
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

    cout << sum << "\n"; // 648
    return 0;
}
