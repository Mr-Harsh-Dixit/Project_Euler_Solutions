#include <iostream>
using namespace std;

int main() {
    long long total = 0;
    for (long long a = 3; a <= 1000; a++) {
        if (a & 1) total += a*a - a;
        else       total += a*a - 2*a;
    }
    cout << total << "\n"; // 333082500
    return 0;
}
