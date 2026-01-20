#include <iostream>
#include <string>
using namespace std;

static int digitAt(long long k) { // 1-indexed
    long long len = 1;
    long long count = 9;
    long long start = 1;

    while (k > len * count) {
        k -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    long long index = (k - 1) / len;
    long long offset = (k - 1) % len;
    long long num = start + index;

    string s = to_string(num);
    return s[(int)offset] - '0';
}

int main() {
    long long positions[] = {1,10,100,1000,10000,100000,1000000};
    long long ans = 1;

    for (long long p : positions) ans *= digitAt(p);

    cout << ans << "\n"; // 210
    return 0;
}
