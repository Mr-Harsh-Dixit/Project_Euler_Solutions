#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

static int digitSum(unsigned long long n) {
    int s = 0;
    while (n) {
        s += (int)(n % 10);
        n /= 10;
    }
    return s;
}

int main() {
    const unsigned long long LIMIT = 1000000000000000000ULL; // 1e18
    unordered_set<unsigned long long> vals;
    vals.reserve(2048);

    for (int s = 2; s <= 500; s++) {
        unsigned long long v = (unsigned long long)s * s; // start at s^2
        while (v <= LIMIT) {
            if (v >= 10 && digitSum(v) == s) vals.insert(v);
            if (v > LIMIT / s) break; // prevent overflow
            v *= s;
        }
    }

    vector<unsigned long long> arr(vals.begin(), vals.end());
    sort(arr.begin(), arr.end());

    cout << arr[29] << "\n"; // 248155780267521
    return 0;
}
