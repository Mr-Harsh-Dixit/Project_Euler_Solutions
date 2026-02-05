#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int m = 50;
    const long long TARGET = 1'000'000;

    vector<long long> F(1, 1); // F[0] = 1
    vector<long long> P(1, 1); // P[0] = 1

    int n = 0;
    while (F[n] <= TARGET) {
        n++;
        long long fn;
        if (n < m) {
            fn = 1;
        } else {
            fn = F[n - 1] + 1 + P[n - m - 1];
        }
        F.push_back(fn);
        P.push_back(P[n - 1] + fn);
    }

    cout << n << "\n"; // 168
    return 0;
}
