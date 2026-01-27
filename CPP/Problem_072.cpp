#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 1'000'000;
    vector<int> phi(N + 1);
    for (int i = 0; i <= N; i++) phi[i] = i;

    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) { // prime
            for (int j = i; j <= N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    long long ans = 0;
    for (int d = 2; d <= N; d++) ans += phi[d];

    cout << ans << "\n"; // 303963552391
    return 0;
}
