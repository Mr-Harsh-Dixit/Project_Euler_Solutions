#include <iostream>
#include <vector>
using namespace std;

static int cycleLength(int d) {
    while (d % 2 == 0) d /= 2;
    while (d % 5 == 0) d /= 5;
    if (d == 1) return 0;

    // seen[remainder] = position, -1 means unseen
    vector<int> seen(d, -1);
    int r = 1 % d;
    int pos = 0;

    while (seen[r] == -1) {
        seen[r] = pos;
        r = (r * 10) % d;
        pos++;
    }
    return pos - seen[r];
}

int main() {
    int bestD = 0, bestLen = 0;

    for (int d = 2; d < 1000; ++d) {
        int len = cycleLength(d);
        if (len > bestLen) {
            bestLen = len;
            bestD = d;
        }
    }

    cout << bestD << "\n"; // 983
    return 0;
}
