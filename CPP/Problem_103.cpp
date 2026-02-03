#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static bool rule2_prefix_suffix(vector<int> a) {
    sort(a.begin(), a.end());
    int n = (int)a.size();
    for (int k = 1; k <= n/2; k++) {
        long long left = 0, right = 0;
        for (int i = 0; i <= k; i++) left += a[i];          // k+1 smallest
        for (int i = 0; i < k; i++) right += a[n-1-i];      // k largest
        if (left <= right) return false;
    }
    return true;
}

static bool rule1_disjoint(const vector<int>& a) {
    int n = (int)a.size();
    unordered_map<long long, int> seen; // sum -> bitmask
    seen.reserve(1 << n);

    for (int mask = 1; mask < (1<<n); mask++) {
        long long s = 0;
        int m = mask, idx = 0;
        while (m) {
            if (m & 1) s += a[idx];
            idx++;
            m >>= 1;
        }
        auto it = seen.find(s);
        if (it == seen.end()) {
            seen.emplace(s, mask);
        } else {
            if ((it->second & mask) == 0) return false; // disjoint equal sum
        }
    }
    return true;
}

static bool is_special(vector<int> a) {
    return rule2_prefix_suffix(a) && rule1_disjoint(a);
}

int main() {
    vector<int> best = {20,31,38,39,40,42,45};
    if (!is_special(best)) return 1;

    for (int x : best) cout << x;
    cout << "\n"; // 20313839404245
    return 0;
}
