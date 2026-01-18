#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int target = 200;
    vector<int> coins = {1,2,5,10,20,50,100,200};
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int x = coin; x <= target; ++x) {
            dp[x] += dp[x - coin];
        }
    }

    cout << dp[target] << "\n"; // 73682
    return 0;
}
