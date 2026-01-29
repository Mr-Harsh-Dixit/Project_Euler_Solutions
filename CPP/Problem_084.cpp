#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

static int toId(int pos, int d) { return pos * 3 + d; }

int main() {
    const int N = 40;
    const int SIDES = 4;
    const int ST = N * 3;
    const int JAIL = 10;
    const int G2J = 30;

    auto isCC = [&](int p){ return p==2 || p==17 || p==33; };
    auto isCH = [&](int p){ return p==7 || p==22 || p==36; };

    vector<int> R = {5, 15, 25, 35};
    vector<int> U = {12, 28};

    auto nextR = [&](int pos){
        for (int r : R) if (r > pos) return r;
        return R[0];
    };
    auto nextU = [&](int pos){
        for (int u : U) if (u > pos) return u;
        return U[0];
    };

    // resolve(pos) -> vector<pair<finalPos, prob>>
    function<vector<pair<int,double>>(int)> resolve = [&](int pos){
        if (pos == G2J) return vector<pair<int,double>>{{JAIL, 1.0}};
        if (isCC(pos)) {
            return vector<pair<int,double>>{
                {0, 1.0/16.0}, {JAIL, 1.0/16.0}, {pos, 14.0/16.0}
            };
        }
        if (isCH(pos)) {
            vector<pair<int,double>> out;
            out.push_back({0, 1.0/16.0});
            out.push_back({JAIL, 1.0/16.0});
            out.push_back({11, 1.0/16.0});
            out.push_back({24, 1.0/16.0});
            out.push_back({39, 1.0/16.0});
            out.push_back({5, 1.0/16.0});
            out.push_back({nextR(pos), 1.0/16.0});
            out.push_back({nextR(pos), 1.0/16.0});
            out.push_back({nextU(pos), 1.0/16.0});

            int back3 = (pos - 3 + N) % N;
            if (isCC(back3)) {
                auto cc = resolve(back3);
                for (auto &pp : cc) out.push_back({pp.first, (1.0/16.0)*pp.second});
            } else {
                out.push_back({back3, 1.0/16.0});
            }

            out.push_back({pos, 6.0/16.0}); // no-move cards
            return out;
        }
        return vector<pair<int,double>>{{pos, 1.0}};
    };

    // transitions
    vector<vector<pair<int,double>>> trans(ST);
    const double pDie = 1.0 / (SIDES * SIDES);

    for (int pos = 0; pos < N; pos++) {
        for (int d = 0; d < 3; d++) {
            int s = toId(pos, d);
            unordered_map<int,double> acc;
            acc.reserve(64);

            for (int a = 1; a <= SIDES; a++) for (int b = 1; b <= SIDES; b++) {
                bool dbl = (a == b);

                if (dbl && d == 2) {
                    acc[toId(JAIL, 0)] += pDie;
                    continue;
                }

                int nd = dbl ? (d + 1) : 0;
                int np = (pos + a + b) % N;

                auto distPos = resolve(np);
                for (auto &fp : distPos) {
                    int finalPos = fp.first;
                    double pr = fp.second;
                    int finalD = (finalPos == JAIL) ? 0 : nd;
                    acc[toId(finalPos, finalD)] += pDie * pr;
                }
            }

            trans[s].assign(acc.begin(), acc.end());
        }
    }

    // power iteration
    vector<double> v(ST, 1.0 / ST), v2(ST, 0.0);
    for (int it = 0; it < 3000; it++) {
        fill(v2.begin(), v2.end(), 0.0);
        for (int s = 0; s < ST; s++) {
            double vs = v[s];
            if (vs == 0.0) continue;
            for (auto &e : trans[s]) v2[e.first] += vs * e.second;
        }
        double diff = 0.0;
        for (int i = 0; i < ST; i++) diff = max(diff, fabs(v2[i] - v[i]));
        v.swap(v2);
        if (diff < 1e-15) break;
    }

    // aggregate by square
    vector<double> sq(N, 0.0);
    for (int pos = 0; pos < N; pos++) {
        sq[pos] = v[toId(pos,0)] + v[toId(pos,1)] + v[toId(pos,2)];
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){ return sq[a] > sq[b]; });

    cout << setw(2) << setfill('0') << idx[0]
         << setw(2) << setfill('0') << idx[1]
         << setw(2) << setfill('0') << idx[2] << "\n"; // 101524
    return 0;
}
