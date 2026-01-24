#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> addDigits(const vector<int>& a, const vector<int>& b) {
    size_t n = max(a.size(), b.size());
    vector<int> out;
    out.reserve(n + 2);
    int carry = 0;

    for (size_t i = 0; i < n; i++) {
        int da = (i < a.size()) ? a[i] : 0;
        int db = (i < b.size()) ? b[i] : 0;
        int s = da + db + carry;
        out.push_back(s % 10);
        carry = s / 10;
    }
    while (carry) {
        out.push_back(carry % 10);
        carry /= 10;
    }
    return out;
}

static vector<int> addScaledDigits(const vector<int>& a, const vector<int>& b, int k) {
    size_t n = max(a.size(), b.size());
    vector<int> out;
    out.reserve(n + 3);
    int carry = 0;

    for (size_t i = 0; i < n; i++) {
        int da = (i < a.size()) ? a[i] : 0;
        int db = (i < b.size()) ? b[i] : 0;
        int s = da + k * db + carry;
        out.push_back(s % 10);
        carry = s / 10;
    }
    while (carry) {
        out.push_back(carry % 10);
        carry /= 10;
    }
    return out;
}

int main() {
    vector<int> p = {3}; // 3
    vector<int> q = {2}; // 2
    int count = 0;

    for (int i = 0; i < 1000; i++) {
        if (p.size() > q.size()) count++;

        vector<int> newP = addScaledDigits(p, q, 2); // p + 2q
        vector<int> newQ = addDigits(p, q);          // p + q
        p.swap(newP);
        q.swap(newQ);
    }

    cout << count << "\n"; // 153
    return 0;
}
