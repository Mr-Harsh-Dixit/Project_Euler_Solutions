#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    long long d;
    int r, c;
    bool operator>(const Node& other) const { return d > other.d; }
};

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
    const long long INF = (long long)4e18;

    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    dist[0][0] = a[0][0];

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({dist[0][0], 0, 0});

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        long long d = cur.d;
        int r = cur.r, c = cur.c;

        if (d != dist[r][c]) continue;
        if (r == n - 1 && c == n - 1) break;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (0 <= nr && nr < n && 0 <= nc && nc < n) {
                long long nd = d + a[nr][nc];
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }
    }

    cout << dist[n - 1][n - 1] << "\n"; // 425185
    return 0;
}
