#include <iostream>
#include <vector>
#include <array>
#include <bitset>
using namespace std;

static vector<int> digits = {0,1,2,3,4,5,6,7,8,9};

static vector<array<int,6>> combos;

void genComb(int start, int idx, array<int,6>& cur) {
    if (idx == 6) {
        combos.push_back(cur);
        return;
    }
    for (int i = start; i <= 10 - (6 - idx); i++) {
        cur[idx] = digits[i];
        genComb(i + 1, idx + 1, cur);
    }
}

static inline void expand69(bitset<10>& b) {
    if (b[6] || b[9]) { b.set(6); b.set(9); }
}

int main() {
    array<int,6> cur{};
    genComb(0, 0, cur);

    vector<bitset<10>> cubes;
    cubes.reserve(combos.size());
    for (auto &c : combos) {
        bitset<10> b;
        for (int x : c) b.set(x);
        cubes.push_back(b);
    }

    vector<pair<int,int>> req = {
        {0,1},{0,4},{0,9},{1,6},{2,5},{3,6},{4,9},{6,4},{8,1}
    };

    long long count = 0;
    int n = (int)cubes.size();

    for (int i = 0; i < n; i++) {
        bitset<10> A = cubes[i];
        expand69(A);

        for (int j = i; j < n; j++) {
            bitset<10> B = cubes[j];
            expand69(B);

            bool ok = true;
            for (auto [x,y] : req) {
                if (!((A[x] && B[y]) || (A[y] && B[x]))) {
                    ok = false;
                    break;
                }
            }
            if (ok) count++;
        }
    }

    cout << count << "\n"; // 1217
    return 0;
}
