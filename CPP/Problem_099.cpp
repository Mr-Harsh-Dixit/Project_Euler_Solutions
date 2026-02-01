#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("base_exp.txt");
    string line;

    int bestLine = -1;
    long double bestScore = -INFINITY;

    int i = 0;
    while (getline(fin, line)) {
        i++;
        auto comma = line.find(',');
        long long b = stoll(line.substr(0, comma));
        long long e = stoll(line.substr(comma + 1));

        long double score = (long double)e * log((long double)b);
        if (score > bestScore) {
            bestScore = score;
            bestLine = i;
        }
    }

    cout << bestLine << "\n"; // 709 for Euler dataset
    return 0;
}
