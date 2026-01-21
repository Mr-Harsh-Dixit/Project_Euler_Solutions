#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

static int wordValue(const string& w) {
    int sum = 0;
    for (char c : w) sum += (c - 'A' + 1);
    return sum;
}

int main() {
    ifstream fin("words.txt");
    string data;
    if (!fin) {
        cerr << "Could not open words.txt\n";
        return 1;
    }
    getline(fin, data);

    vector<string> words;
    words.reserve(2000);

    // Parse CSV like: "ABC","DEF","GHI"
    string cur;
    for (char c : data) {
        if (c == '"') continue;
        if (c == ',') {
            words.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    if (!cur.empty()) words.push_back(cur);

    int maxVal = 0;
    vector<int> vals;
    vals.reserve(words.size());
    for (const auto& w : words) {
        int v = wordValue(w);
        vals.push_back(v);
        if (v > maxVal) maxVal = v;
    }

    unordered_set<int> tri;
    for (int n = 1;; ++n) {
        int t = n * (n + 1) / 2;
        if (t > maxVal) break;
        tri.insert(t);
    }

    int count = 0;
    for (int v : vals) if (tri.find(v) != tri.end()) count++;

    cout << count << "\n"; // 162 for Project Euler words.txt
    return 0;
}
