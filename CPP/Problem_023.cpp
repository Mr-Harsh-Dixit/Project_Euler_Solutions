#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int LIMIT = 28123;

    vector<int> d(LIMIT + 1, 0);
    for (int i = 1; i <= LIMIT / 2; ++i) {
        for (int j = 2 * i; j <= LIMIT; j += i) {
            d[j] += i;
        }
    }

    vector<int> abundants;
    abundants.reserve(8000);
    for (int n = 12; n <= LIMIT; ++n) {
        if (d[n] > n) abundants.push_back(n);
    }

    vector<char> can(LIMIT + 1, 0);
    for (int i = 0; i < (int)abundants.size(); ++i) {
        int a = abundants[i];
        for (int j = i; j < (int)abundants.size(); ++j) {
            int s = a + abundants[j];
            if (s > LIMIT) break;
            can[s] = 1;
        }
    }

    long long sum = 0;
    for (int n = 1; n <= LIMIT; ++n) {
        if (!can[n]) sum += n;
    }

    cout << sum << "\n"; // 4179871
    return 0;
}
