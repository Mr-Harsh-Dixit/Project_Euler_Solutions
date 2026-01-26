#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    vector<int> all;
    for (int i = 1; i <= 10; i++) all.push_back(i);

    string best = "";

    // iterate all 5-permutations for inner nodes
    vector<int> choose = all;
    // We'll generate by permutations of 10 and take first 5 as inner (works but more work)
    // Better: generate combinations then permute, but 10P5 = 30240 so direct is fine.

    vector<int> perm = all;
    sort(perm.begin(), perm.end());

    // generate all 5-length permutations by selecting indices: simplest approach
    // We'll do nested loops over distinct picks (still 10P5 = 30240).
    for (int a = 1; a <= 10; a++)
    for (int b = 1; b <= 10; b++) if (b != a)
    for (int c = 1; c <= 10; c++) if (c != a && c != b)
    for (int d = 1; d <= 10; d++) if (d != a && d != b && d != c)
    for (int e = 1; e <= 10; e++) if (e != a && e != b && e != c && e != d) {
        int I[5] = {a,b,c,d,e};
        bool has10 = (a==10||b==10||c==10||d==10||e==10);
        if (has10) continue; // 10 must be external

        bool inInner[11] = {false};
        for (int i = 0; i < 5; i++) inInner[I[i]] = true;

        // remaining numbers are candidates for E0
        for (int E0 = 1; E0 <= 10; E0++) {
            if (inInner[E0]) continue;

            int S = E0 + I[0] + I[1];
            int E[5];
            E[0] = E0;

            bool usedE[11] = {false};
            usedE[E0] = true;
            bool ok = true;

            for (int k = 1; k < 5; k++) {
                int ek = S - I[k] - I[(k+1)%5];
                if (ek < 1 || ek > 10 || inInner[ek] || usedE[ek]) { ok = false; break; }
                usedE[ek] = true;
                E[k] = ek;
            }
            if (!ok) continue;

            // check 10 is external
            if (!usedE[10]) continue;

            // build triplets
            array<array<int,3>,5> t;
            for (int k = 0; k < 5; k++) {
                t[k] = {E[k], I[k], I[(k+1)%5]};
            }

            // rotate so smallest external starts
            int minIdx = 0;
            for (int k = 1; k < 5; k++) if (t[k][0] < t[minIdx][0]) minIdx = k;

            string s = "";
            for (int k = 0; k < 5; k++) {
                auto tri = t[(minIdx + k) % 5];
                s += to_string(tri[0]) + to_string(tri[1]) + to_string(tri[2]);
            }

            if ((int)s.size() == 16 && s > best) best = s;
        }
    }

    cout << best << "\n"; // 6531031914842725
    return 0;
}
