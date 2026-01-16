#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 10000;
    vector<int> d(N, 0);

    for (int i = 1; i <= N / 2; ++i) {
        for (int j = 2 * i; j < N; j += i) {
            d[j] += i;
        }
    }

    long long sum = 0;
    for (int a = 2; a < N; ++a) {
        int b = d[a];
        if (b != a && b < N && d[b] == a) {
            sum += a;
        }
    }

    cout << sum << "\n"; // 31626
    return 0;
}
