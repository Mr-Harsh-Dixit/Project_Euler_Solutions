#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int romanToInt(const string& s) {
    unordered_map<char,int> v{
        {'I',1},{'V',5},{'X',10},{'L',50},
        {'C',100},{'D',500},{'M',1000}
    };
    int total = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (i+1 < (int)s.size() && v[s[i]] < v[s[i+1]])
            total -= v[s[i]];
        else
            total += v[s[i]];
    }
    return total;
}

string intToRoman(int n) {
    vector<pair<int,string>> t = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
        {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
        {10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
    };
    string res;
    for (auto &p : t) {
        while (n >= p.first) {
            res += p.second;
            n -= p.first;
        }
    }
    return res;
}

int main() {
    ifstream in("roman.txt");
    string s;
    long long saved = 0;

    while (in >> s) {
        int v = romanToInt(s);
        string m = intToRoman(v);
        saved += (long long)s.size() - (long long)m.size();
    }

    cout << saved << "\n"; // 743
    return 0;
}
