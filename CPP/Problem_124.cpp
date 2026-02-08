#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100000;
    const int K = 10000;

    vector<int> rad(N + 1, 1);

    for (int p = 2; p <= N; p++) {
        if (rad[p] == 1) { // prime
            for (int m = p; m <= N; m += p) {
                rad[m] *= p;
            }
        }
    }

    vector<pair<int,int>> v;
    v.reserve(N);
    for (int n = 1; n <= N; n++) v.push_back({rad[n], n});

    sort(v.begin(), v.end()); // (rad, n)
    cout << v[K - 1].second << "\n"; // 21417
    return 0;
}
