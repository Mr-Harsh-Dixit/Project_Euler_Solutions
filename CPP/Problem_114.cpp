#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 50;
    vector<long long> F(N + 1, 0);
    F[0] = 1;

    for (int i = 1; i <= N; i++) {
        // Leading grey
        F[i] = F[i - 1];

        // Red block k >= 3 followed by grey
        for (int k = 3; k < i; k++) {
            F[i] += F[i - k - 1];
        }

        // Red block reaches the end
        if (i >= 3) F[i] += 1;
    }

    cout << F[N] << "\n"; // 16475640049
    return 0;
}
