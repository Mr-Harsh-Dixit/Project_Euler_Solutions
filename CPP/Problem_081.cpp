#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("matrix.txt");
    vector<vector<long long>> a;
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        vector<long long> row;
        string x;
        while (getline(ss, x, ',')) row.push_back(stoll(x));
        a.push_back(row);
    }

    int n = a.size();
    vector<vector<long long>> dp(n, vector<long long>(n));

    dp[0][0] = a[0][0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        dp[0][i] = dp[0][i - 1] + a[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n - 1][n - 1] << "\n"; // 427337
    return 0;
}
