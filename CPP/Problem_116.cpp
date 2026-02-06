#include <iostream>
#include <vector>
using namespace std;

static long long ways(int n, int m) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (i >= m) dp[i] += dp[i - m];
    }
    return dp[n] - 1; // exclude all-grey
}

int main() {
    int n = 50;
    long long ans = ways(n, 2) + ways(n, 3) + ways(n, 4);
    cout << ans << "\n"; // 20492570929
    return 0;
}
