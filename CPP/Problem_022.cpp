#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static long long nameValue(const string& name) {
    long long sum = 0;
    for (char c : name) sum += (c - 'A' + 1);
    return sum;
}

int main() {
    ifstream fin("names.txt");
    string content;
    getline(fin, content);

    vector<string> names;
    string cur;

    for (char c : content) {
        if (c == '"') continue;
        if (c == ',') {
            names.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    if (!cur.empty()) names.push_back(cur);

    sort(names.begin(), names.end());

    long long total = 0;
    for (int i = 0; i < (int)names.size(); ++i) {
        total += 1LL * (i + 1) * nameValue(names[i]);
    }

    cout << total << "\n"; // 871198282
    return 0;
}
