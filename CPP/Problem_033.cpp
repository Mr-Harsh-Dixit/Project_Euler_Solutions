#include <iostream>
#include <string>
using namespace std;

static long long gcdll(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    long long numProd = 1, denProd = 1;

    for (int n = 10; n < 100; ++n) {
        for (int d = n + 1; d < 100; ++d) {
            if (n % 10 == 0 && d % 10 == 0) continue; // trivial

            string ns = to_string(n);
            string ds = to_string(d);

            for (char c : ns) {
                if (c == '0') continue;
                size_t pos = ds.find(c);
                if (pos == string::npos) continue;

                // remove one occurrence
                string n2s = ns;
                string d2s = ds;
                n2s.erase(n2s.find(c), 1);
                d2s.erase(d2s.find(c), 1);

                int n2 = stoi(n2s);
                int d2 = stoi(d2s);
                if (d2 != 0 && 1LL * n * d2 == 1LL * d * n2) {
                    numProd *= n;
                    denProd *= d;
                }
            }
        }
    }

    long long g = gcdll(numProd, denProd);
    cout << (denProd / g) << "\n"; // 100
    return 0;
}
