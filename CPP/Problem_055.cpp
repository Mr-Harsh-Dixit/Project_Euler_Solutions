#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// String-based big integer addition
string addStrings(string num1, string num2) {
    string result = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result = char((sum % 10) + '0') + result;
        carry = sum / 10;
    }
    return result;
}

static bool isPalindrome(const string& s) {
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

static string reverseInt(const string& x) {
    string s = x;
    reverse(s.begin(), s.end());
    return s;
}

static bool isLychrel(int n, int maxIter = 50) {
    string x = to_string(n);
    for (int i = 0; i < maxIter; i++) {
        x = addStrings(x, reverseInt(x));
        if (isPalindrome(x)) return false;
    }
    return true;
}

int main() {
    int count = 0;
    for (int n = 1; n < 10000; n++) {
        if (isLychrel(n)) count++;
    }
    cout << count << "\n"; // 249
    return 0;
}
