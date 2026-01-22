#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int LIMIT = 1000000;
    vector<int> cnt(LIMIT + 1, 0);

    for (int i = 2; i <= LIMIT; ++i) {
        if (cnt[i] == 0) { // prime
            for (int m = i; m <= LIMIT; m += i) {
                cnt[m] += 1;
            }
        }
    }

    int streak = 0;
    for (int n = 2; n <= LIMIT; ++n) {
        if (cnt[n] == 4) {
            streak++;
            if (streak == 4) {
                cout << (n - 3) << "\n"; // 134043
                return 0;
            }
        } else {
            streak = 0;
        }
    }

    return 0;
}
