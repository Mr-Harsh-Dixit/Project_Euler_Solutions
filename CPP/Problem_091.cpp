#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

static long long maxSteps(int x, int y, int dx, int dy, int N) {
    const long long INF = (1LL<<60);
    long long lim = INF;

    if (dx > 0) lim = min(lim, (long long)(N - x) / dx);
    else if (dx < 0) lim = min(lim, (long long)x / (-dx));

    if (dy > 0) lim = min(lim, (long long)(N - y) / dy);
    else if (dy < 0) lim = min(lim, (long long)y / (-dy));

    return (lim == INF) ? 0 : lim;
}

int main() {
    const int N = 50;
    long long ans = 1LL * N * N; // right angle at origin

    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            if (x == 0 && y == 0) continue;

            int g = std::gcd(x, y);
            int dx = -y / g;
            int dy =  x / g;

            ans += maxSteps(x, y, dx, dy, N);
            ans += maxSteps(x, y, -dx, -dy, N);
        }
    }

    cout << ans << "\n"; // 14234
    return 0;
}
