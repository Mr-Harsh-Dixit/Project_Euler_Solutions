#include <iostream>
#include <string>
using namespace std;

static bool isPandigital9(const string& s) {
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
    int best = 0;

    for (int x = 9876; x >= 9123; --x) {
        int y = 2 * x;
        string s = to_string(x) + to_string(y);
        if (isPandigital9(s)) {
            best = stoi(s);
            break; // first found is maximum
        }
    }

    cout << best << "\n"; // 932718654
    return 0;
}
