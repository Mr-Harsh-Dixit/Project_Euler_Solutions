#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int LIMIT = 10'000'000;
    const int MAXS = 567; // 7*81

    int digitSq[10];
    for (int i = 0; i < 10; i++) digitSq[i] = i * i;

    vector<int> fate(MAXS + 1, 0);
    fate[1] = 1;
    fate[89] = 89;

    auto nextSum = [&](int n) {
        int s = 0;
        while (n) {
            s += digitSq[n % 10];
            n /= 10;
        }
        return s;
    };

    auto resolve = [&](int start) {
        int s = start;
        vector<int> path;
        while (fate[s] == 0) {
            path.push_back(s);
            s = nextSum(s);
        }
        int end = fate[s];
        for (int v : path) fate[v] = end;
    };

    for (int s = 1; s <= MAXS; s++) {
        if (fate[s] == 0) resolve(s);
    }

    int count = 0;
    for (int n = 1; n < LIMIT; n++) {
        int s = nextSum(n);
        if (fate[s] == 89) count++;
    }

    cout << count << "\n"; // 8581146
    return 0;
}
