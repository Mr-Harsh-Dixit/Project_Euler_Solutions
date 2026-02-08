#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

int main() {
    int n = 15;

    vector<cpp_int> dp(1);
    dp[0] = 1;
    cpp_int D = 1;

    for (int i = 1; i <= n; i++) {
        D *= (i + 1);
        vector<cpp_int> nw(dp.size() + 1);
        for (int k = 0; k < (int)dp.size(); k++) {
            nw[k]     += dp[k] * i; // red
            nw[k + 1] += dp[k];     // blue
        }
        dp.swap(nw);
    }

    int need = n / 2 + 1;
    cpp_int win_num = 0;
    for (int k = need; k <= n; k++) win_num += dp[k];

    cpp_int ans = D / win_num; // floor(1/p)
    cout << ans << "\n";       // 2269
    return 0;
}
