#include <iostream>
#include <vector>
#include <string>
using namespace std;

static long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; ++i) f *= i;
    return f;
}

int main() {
    vector<char> digits = {'0','1','2','3','4','5','6','7','8','9'};
    long long k = 1'000'000 - 1; // 0-based

    string result;
    result.reserve(10);

    for (int n = (int)digits.size(); n >= 1; --n) {
        long long f = factorial(n - 1);
        long long idx = k / f;
        k %= f;

        result.push_back(digits[(int)idx]);
        digits.erase(digits.begin() + (int)idx);
    }

    cout << result << "\n"; // 2783915460
    return 0;
}
