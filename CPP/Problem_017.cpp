#include <iostream>
using namespace std;

int main() {
    int ones[10] = {0,3,3,5,4,4,3,5,5,4};
    int teens[20] = {0};
    teens[10]=3; teens[11]=6; teens[12]=6; teens[13]=8; teens[14]=8;
    teens[15]=7; teens[16]=7; teens[17]=9; teens[18]=8; teens[19]=8;

    int tens[10] = {0};
    tens[2]=6; tens[3]=6; tens[4]=5; tens[5]=5; tens[6]=5; tens[7]=7; tens[8]=6; tens[9]=6;

    const int HUNDRED = 7, AND = 3, THOUSAND = 8;

    auto letters = [&](int n) -> int {
        if (n == 1000) return ones[1] + THOUSAND;

        int total = 0;

        if (n >= 100) {
            int h = n / 100;
            total += ones[h] + HUNDRED;
            if (n % 100 != 0) total += AND;
            n %= 100;
        }

        if (n >= 20) {
            total += tens[n / 10];
            total += ones[n % 10];
        } else if (n >= 10) {
            total += teens[n];
        } else {
            total += ones[n];
        }

        return total;
    };

    long long sum = 0;
    for (int i = 1; i <= 1000; ++i) sum += letters(i);

    cout << sum << "\n"; // 21124
    return 0;
}
