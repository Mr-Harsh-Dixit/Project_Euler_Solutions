#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// digits stored least-significant first
using Big = vector<int>;

Big add(const Big& a, const Big& b) {
    Big r;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    for (size_t i = 0; i < n; i++) {
        int da = i < a.size() ? a[i] : 0;
        int db = i < b.size() ? b[i] : 0;
        int s = da + db + carry;
        r.push_back(s % 10);
        carry = s / 10;
    }
    while (carry) {
        r.push_back(carry % 10);
        carry /= 10;
    }
    return r;
}

Big mulSmall(const Big& a, int m) {
    Big r;
    int carry = 0;
    for (int d : a) {
        int s = d * m + carry;
        r.push_back(s % 10);
        carry = s / 10;
    }
    while (carry) {
        r.push_back(carry % 10);
        carry /= 10;
    }
    return r;
}

int main() {
    int a[100];
    a[0] = 2;
    for (int i = 1; i < 100; i++) {
        if (i % 3 == 2) a[i] = 2 * ((i + 1) / 3);
        else a[i] = 1;
    }

    Big pprev = {0};
    Big pcurr = {1};

    for (int i = 0; i < 100; i++) {
        Big term = mulSmall(pcurr, a[i]);
        Big pnext = add(term, pprev);
        pprev = pcurr;
        pcurr = pnext;
    }

    int sum = 0;
    for (int d : pcurr) sum += d;

    cout << sum << "\n"; // 272
    return 0;
}
