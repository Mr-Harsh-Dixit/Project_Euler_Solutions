#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;

static vector<int> patternKey(const string &s) {
    unordered_map<char,int> mp;
    mp.reserve(s.size() * 2);
    vector<int> out;
    out.reserve(s.size());
    int nxt = 0;
    for (char ch : s) {
        auto it = mp.find(ch);
        if (it == mp.end()) {
            mp[ch] = nxt;
            out.push_back(nxt);
            nxt++;
        } else {
            out.push_back(it->second);
        }
    }
    return out;
}

static bool buildMap(const string &word, const string &num,
                     array<char,26> &l2d, array<char,10> &d2l) {
    l2d.fill(0);
    d2l.fill(0);
    for (int i = 0; i < (int)word.size(); i++) {
        int li = word[i] - 'A';
        int di = num[i] - '0';
        char needD = (char)('0' + di);

        if (l2d[li] && l2d[li] != needD) return false;
        if (d2l[di] && d2l[di] != word[i]) return false;

        l2d[li] = needD;
        d2l[di] = word[i];
    }
    if (l2d[word[0] - 'A'] == '0') return false;
    return true;
}

static string applyMap(const string &word, const array<char,26> &l2d) {
    string out = word;
    for (int i = 0; i < (int)word.size(); i++) out[i] = l2d[word[i] - 'A'];
    return out;
}

int main() {
    // Read file as one line
    ifstream fin("words.txt");
    string raw;
    getline(fin, raw);

    // Parse CSV of quoted words
    vector<string> words;
    {
        string cur;
        for (char ch : raw) {
            if (ch == '"') continue;
            if (ch == ',') {
                words.push_back(cur);
                cur.clear();
            } else cur.push_back(ch);
        }
        if (!cur.empty()) words.push_back(cur);
    }

    // Group anagrams by sorted signature
    unordered_map<string, vector<string>> groups;
    groups.reserve(words.size() * 2);

    for (string w : words) {
        sort(w.begin(), w.end());
        // Need original word too; reconstruct by sorting a copy instead
    }
    // Re-do properly:
    groups.clear();
    for (const string &w : words) {
        string sig = w;
        sort(sig.begin(), sig.end());
        groups[sig].push_back(w);
    }

    // Precompute squares by length on demand
    unordered_map<int, vector<string>> squaresList;
    unordered_map<int, unordered_set<string>> squaresSet;

    auto ensureSquares = [&](int L) {
        if (squaresList.count(L)) return;
        long long lo = 1;
        for (int i = 1; i < L; i++) lo *= 10;
        long long hi = lo * 10 - 1;

        long long a = (long long)floor(sqrt((long double)lo));
        while (a*a < lo) a++;
        long long b = (long long)floor(sqrt((long double)hi));

        vector<string> lst;
        lst.reserve((size_t)(b - a + 1));
        unordered_set<string> st;
        st.reserve((size_t)(b - a + 1) * 2);

        for (long long x = a; x <= b; x++) {
            long long sq = x * x;
            string s = to_string(sq);
            lst.push_back(s);
            st.insert(s);
        }
        squaresList[L] = move(lst);
        squaresSet[L] = move(st);
    };

    long long best = 0;
    array<char,26> l2d;
    array<char,10> d2l;

    for (auto &kv : groups) {
        auto &ws = kv.second;
        if (ws.size() < 2) continue;

        for (int i = 0; i < (int)ws.size(); i++) {
            for (int j = i + 1; j < (int)ws.size(); j++) {
                const string &a = ws[i];
                const string &b = ws[j];
                int L = (int)a.size();
                if ((int)b.size() != L) continue;

                ensureSquares(L);

                auto pa = patternKey(a);
                auto pb = patternKey(b);

                for (const string &sq : squaresList[L]) {
                    if (patternKey(sq) != pa) continue;

                    if (!buildMap(a, sq, l2d, d2l)) continue;

                    string other = applyMap(b, l2d);
                    if (other[0] == '0') continue;

                    if (squaresSet[L].count(other) && patternKey(other) == pb) {
                        best = max(best, stoll(sq));
                        best = max(best, stoll(other));
                    }
                }
            }
        }
    }

    cout << best << "\n"; // 18769
    return 0;
}
