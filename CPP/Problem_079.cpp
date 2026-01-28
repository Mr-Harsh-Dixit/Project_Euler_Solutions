#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <array>
#include <string>
using namespace std;

int main() {
    ifstream in("keylog.txt");
    vector<string> attempts;
    string s;
    while (in >> s) attempts.push_back(s);

    vector<bool> used(10, false);
    vector<array<bool,10>> adj(10);
    for (int i = 0; i < 10; i++) adj[i].fill(false);

    vector<int> indeg(10, 0);

    auto add_edge = [&](int u, int v) {
        if (!adj[u][v]) {
            adj[u][v] = true;
            indeg[v]++;
        }
    };

    for (auto &t : attempts) {
        int a = t[0]-'0', b = t[1]-'0', c = t[2]-'0';
        used[a] = used[b] = used[c] = true;
        add_edge(a, b);
        add_edge(b, c);
    }

    // min-heap of available nodes (smallest digit first)
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int d = 0; d <= 9; d++) {
        if (used[d] && indeg[d] == 0) pq.push(d);
    }

    string result;
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        result.push_back(char('0' + u));
        for (int v = 0; v <= 9; v++) {
            if (adj[u][v]) {
                indeg[v]--;
                if (indeg[v] == 0) pq.push(v);
            }
        }
    }

    cout << result << "\n"; // 73162890 for official file
    return 0;
}
