#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

static bool rule2_quick(vector<int> a) {
    sort(a.begin(), a.end());
    int n = (int)a.size();
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    for (int k = 1; k <= n / 2; k++) {
        long long left = pref[k + 1]; // smallest k+1
        long long right = 0;
        for (int i = 0; i < k; i++) right += a[n - 1 - i]; // largest k
        if (left <= right) return false;
    }
    return true;
}

static bool rule1_disjoint(const vector<int>& a) {
    int n = (int)a.size();
    unordered_map<long long, int> seen;
    seen.reserve(1 << n);

    for (int mask = 1; mask < (1 << n); mask++) {
        long long s = 0;
        int m = mask, i = 0;
        while (m) {
            if (m & 1) s += a[i];
            i++;
            m >>= 1;
        }

        auto it = seen.find(s);
        if (it == seen.end()) {
            seen.emplace(s, mask);
        } else {
            if ((it->second & mask) == 0) return false; // disjoint collision
        }
    }
    return true;
}

static bool is_special(vector<int> a) {
    sort(a.begin(), a.end());
    return rule2_quick(a) && rule1_disjoint(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream in("sets.txt");
    string line;
    long long ans = 0;

    while (getline(in, line)) {
        vector<int> a;
        int x = 0, sign = 1;
        bool inNum = false;

        // manual parse (commas)
        for (size_t i = 0; i <= line.size(); i++) {
            char c = (i == line.size()) ? ',' : line[i];
            if (c == '-') { sign = -1; }
            else if (isdigit((unsigned char)c)) { x = x * 10 + (c - '0'); inNum = true; }
            else if (c == ',' && inNum) {
                a.push_back(sign * x);
                x = 0; sign = 1; inNum = false;
            }
        }

        if (!a.empty() && is_special(a)) {
            long long s = 0;
            for (int v : a) s += v;
            ans += s;
        }
    }

    cout << ans << "\n"; // 73702 
    return 0;
}
