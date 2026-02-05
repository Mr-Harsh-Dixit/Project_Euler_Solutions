#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long cpp_int;

static cpp_int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);

    cpp_int res = 1;
    for (int i = 1; i <= r; i++) {
        // res *= (n - r + i); res /= i; with exact division each step
        res *= (n - r + i);
        res /= i;
    }
    return res;
}

static cpp_int non_bouncy_below_10_pow_n(int n) {
    // NB(n) = C(n+9,9) + C(n+10,10) - 10n - 2
    cpp_int a = nCr(n + 9, 9);
    cpp_int b = nCr(n + 10, 10);
    cpp_int correction = (cpp_int)10 * n + 2;
    return a + b - correction;
}

int main() {
    cpp_int result = non_bouncy_below_10_pow_n(100);
    // Manual conversion since __int128 doesn't have direct cout support
    string output = "";
    if (result == 0) {
        output = "0";
    } else {
        while (result > 0) {
            output = char('0' + result % 10) + output;
            result /= 10;
        }
    }
    cout << output << "\n"; // 51161058134250
    return 0;
}
