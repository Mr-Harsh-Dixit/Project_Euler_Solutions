#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

static vector<int> readCipher(const string& path) {
    ifstream in(path);
    string s;
    getline(in, s);
    vector<int> c;
    int x = 0;
    bool inNum = false;
    for (char ch : s) {
        if (isdigit(ch)) {
            x = x * 10 + (ch - '0');
            inNum = true;
        } else {
            if (inNum) c.push_back(x);
            x = 0;
            inNum = false;
        }
    }
    if (inNum) c.push_back(x);
    return c;
}

static bool printable(int p) {
    return p == 10 || (p >= 32 && p <= 126);
}

static int scoreEnglish(const string& text) {
    string t = " " + text + " ";
    for (char &ch : t) ch = (char)tolower((unsigned char)ch);
    vector<string> common = {" the ", " and ", " of ", " to ", " in ", " that ", " is ", " was "};

    int score = 0;
    for (const auto& w : common) {
        size_t pos = 0;
        while ((pos = t.find(w, pos)) != string::npos) {
            score++;
            pos += 1;
        }
    }
    return score;
}

int main() {
    auto cipher = readCipher("0059_cipher.txt");

    int bestScore = -1;
    string bestKey, bestPlain;

    for (int a = 'a'; a <= 'z'; a++) {
        for (int b = 'a'; b <= 'z'; b++) {
            for (int c = 'a'; c <= 'z'; c++) {
                int key[3] = {a, b, c};
                string plain;
                plain.reserve(cipher.size());
                bool ok = true;

                for (size_t i = 0; i < cipher.size(); i++) {
                    int p = cipher[i] ^ key[i % 3];
                    if (!printable(p)) { ok = false; break; }
                    plain.push_back((char)p);
                }
                if (!ok) continue;

                int sc = scoreEnglish(plain);
                if (sc > bestScore) {
                    bestScore = sc;
                    bestKey = string({(char)a, (char)b, (char)c});
                    bestPlain = plain;
                }
            }
        }
    }

    long long asciiSum = 0;
    for (unsigned char ch : bestPlain) asciiSum += (int)ch;

    cout << bestKey << " " << asciiSum << "\n"; // god 129448 (official file)
    return 0;
}
