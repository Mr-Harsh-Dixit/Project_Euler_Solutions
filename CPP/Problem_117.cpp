#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 50;
    vector<long long> f(N + 1, 0);
    f[0] = 1;

    for (int i = 1; i <= N; i++) {
        long long v = f[i - 1];
        if (i >= 2) v += f[i - 2];
        if (i >= 3) v += f[i - 3];
        if (i >= 4) v += f[i - 4];
        f[i] = v;
    }

    cout << f[N] << "\n"; // 100808458960497
    return 0;
}
