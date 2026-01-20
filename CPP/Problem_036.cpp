#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static bool isPal(const string& s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

static string toBinary(int n) {
    string s;
    while (n > 0) {
        s.push_back((n & 1) ? '1' : '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    const int LIMIT = 1'000'000;
    long long total = 0;

    for (int n = 1; n < LIMIT; n += 2) { // only odd
        string dec = to_string(n);
        if (!isPal(dec)) continue;

        string bin = toBinary(n);
        if (isPal(bin)) total += n;
    }

    cout << total << "\n"; // 872187
    return 0;
}
