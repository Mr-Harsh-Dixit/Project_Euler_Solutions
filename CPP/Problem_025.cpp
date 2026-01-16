#include <iostream>
#include <vector>
using namespace std;

static vector<int> addBig(const vector<int>& A, const vector<int>& B) {
    int n = max(A.size(), B.size());
    vector<int> C;
    C.reserve(n + 1);

    int carry = 0;
    for (int i = 0; i < n; ++i) {
        int sum = carry;
        if (i < (int)A.size()) sum += A[i];
        if (i < (int)B.size()) sum += B[i];
        C.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry) C.push_back(carry);
    return C;
}

int main() {
    vector<int> a = {1}; // F1
    vector<int> b = {1}; // F2
    int idx = 2;

    while ((int)b.size() < 1000) {
        vector<int> c = addBig(a, b);
        a = b;
        b = c;
        idx++;
    }

    cout << idx << "\n"; // 4782
    return 0;
}
