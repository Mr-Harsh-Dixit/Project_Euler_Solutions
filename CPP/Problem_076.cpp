#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 100;
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;

    for (int part = 1; part <= 99; part++) {
        for (int s = part; s <= N; s++) {
            dp[s] += dp[s - part];
        }
    }

    cout << dp[N] << "\n"; // 190569291
    return 0;
}
