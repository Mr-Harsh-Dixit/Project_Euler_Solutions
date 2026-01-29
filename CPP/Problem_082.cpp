#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
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

    int n = (int)a.size();
    vector<long long> dp(n);
    for (int r = 0; r < n; r++) dp[r] = a[r][0];

    for (int c = 1; c < n; c++) {
        vector<long long> dp2(n);
        for (int r = 0; r < n; r++) dp2[r] = dp[r] + a[r][c];

        for (int r = 1; r < n; r++) {
            dp2[r] = min(dp2[r], dp2[r - 1] + a[r][c]);
        }
        for (int r = n - 2; r >= 0; r--) {
            dp2[r] = min(dp2[r], dp2[r + 1] + a[r][c]);
        }

        dp.swap(dp2);
    }

    cout << *min_element(dp.begin(), dp.end()) << "\n"; // 260324
    return 0;
}
