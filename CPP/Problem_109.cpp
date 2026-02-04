#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> all, finish;

    for (int v = 1; v <= 20; v++) {
        all.push_back(v);       // S
        all.push_back(2*v);    // D
        all.push_back(3*v);    // T
        finish.push_back(2*v); // D only
    }

    all.push_back(25);   // outer bull
    all.push_back(50);   // inner bull (D25)
    finish.push_back(50);

    sort(all.begin(), all.end());

    int ans = 0;

    for (int f : finish) {
        if (f < 100) ans++;

        for (int i = 0; i < (int)all.size(); i++) {
            int a = all[i];
            if (a + f < 100) ans++;
            else continue;

            for (int j = i; j < (int)all.size(); j++) {
                int b = all[j];
                if (a + b + f < 100) ans++;
            }
        }
    }

    cout << ans << "\n"; // 38182
    return 0;
}
