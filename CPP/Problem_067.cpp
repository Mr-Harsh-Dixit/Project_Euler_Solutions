#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("triangle.txt");
    vector<vector<int>> tri;
    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<int> row;
        int x;
        while (ss >> x) row.push_back(x);
        tri.push_back(row);
    }

    vector<int> dp = tri.back();
    for (int r = (int)tri.size() - 2; r >= 0; --r) {
        for (int c = 0; c <= r; ++c) {
            dp[c] = tri[r][c] + max(dp[c], dp[c + 1]);
        }
    }

    cout << dp[0] << "\n"; // 7273 
    return 0;
}
