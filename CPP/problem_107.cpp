#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream in("network.txt");
    vector<vector<string>> rows;
    string line;

    while (getline(in, line)) {
        vector<string> parts;
        string cur;
        for (char c : line) {
            if (c == ',') { parts.push_back(cur); cur.clear(); }
            else cur.push_back(c);
        }
        parts.push_back(cur);
        rows.push_back(parts);
    }

    int n = (int)rows.size();
    vector<tuple<int,int,int>> edges;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            string &v = rows[i][j];
            if (v != "-") {
                int w = stoi(v);
                total += w;
                edges.emplace_back(w, i, j);
            }
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n);

    long long mst = 0;
    int used = 0;
    for (auto &[w,u,v] : edges) {
        if (dsu.unite(u,v)) {
            mst += w;
            if (++used == n-1) break;
        }
    }

    cout << (total - mst) << "\n"; // 259679 for official file
    return 0;
}
