#include <iostream>
#include <string>
#include <set>
using namespace std;

static bool isPandigital(int a, int b, int p) {
    string s = to_string(a) + to_string(b) + to_string(p);
    if (s.size() != 9) return false;

    bool seen[10] = {false};
    for (char c : s) {
        int d = c - '0';
        if (d == 0 || seen[d]) return false;
        seen[d] = true;
    }
    return true;
}

int main() {
    set<int> prods;

    for (int a = 1; a <= 9; ++a) {
        for (int b = 1234; b <= 9876; ++b) {
            int p = a * b;
            if (p >= 1000 && p <= 9999 && isPandigital(a, b, p)) {
                prods.insert(p);
            }
        }
    }

    for (int a = 12; a <= 98; ++a) {
        for (int b = 123; b <= 987; ++b) {
            int p = a * b;
            if (p >= 1000 && p <= 9999 && isPandigital(a, b, p)) {
                prods.insert(p);
            }
        }
    }

    long long sum = 0;
    for (int x : prods) sum += x;

    cout << sum << "\n"; // 45228
    return 0;
}
