#include <iostream>
using namespace std;

static bool isLeap(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return (year % 4 == 0);
}

static int daysInMonth(int year, int month) {
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    if (month == 2) return isLeap(year) ? 29 : 28;
    return 31;
}

int main() {
    // 0=Mon,1=Tue,...,6=Sun
    int weekday = 0; // 1 Jan 1900 is Monday
    int count = 0;

    for (int year = 1900; year <= 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            if (year >= 1901 && weekday == 6) {
                count++;
            }
            weekday = (weekday + daysInMonth(year, month)) % 7;
        }
    }

    cout << count << "\n"; // 171
    return 0;
}
