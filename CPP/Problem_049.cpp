#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

static vector<char> sieve(int limit) {
    vector<char> isPrime(limit + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; 1LL * p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (long long x = 1LL * p * p; x <= limit; x += p)
                isPrime[(int)x] = 0;
        }
    }
    return isPrime;
}

static string signature(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());
    return s;
}

int main() {
    auto isPrime = sieve(9999);

    unordered_map<string, vector<int>> groups;
    for (int p = 1000; p <= 9999; ++p) {
        if (isPrime[p]) {
            groups[signature(p)].push_back(p);
        }
    }

    for (auto &kv : groups) {
        auto &arr = kv.second;
        if (arr.size() < 3) continue;
        sort(arr.begin(), arr.end());
        unordered_set<int> st(arr.begin(), arr.end());

        for (size_t i = 0; i < arr.size(); ++i) {
            for (size_t j = i + 1; j < arr.size(); ++j) {
                int a = arr[i], b = arr[j];
                int c = 2 * b - a;
                if (st.find(c) != st.end()) {
                    if (a == 1487 && b == 4817) continue;
                    cout << a << b << c << "\n"; // 296962999629
                    return 0;
                }
            }
        }
    }

    return 0;
}
