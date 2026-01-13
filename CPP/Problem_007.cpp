#include <iostream>
#include <vector>
#include <cmath>

int main() {
    const int n = 10001;
    const int limit = 200000; // safely above the 10001st prime

    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    int root = static_cast<int>(std::sqrt(limit));
    for (int p = 2; p <= root; ++p) {
        if (is_prime[p]) {
            for (int x = p * p; x <= limit; x += p) {
                is_prime[x] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            ++count;
            if (count == n) {
                std::cout << i << "\n"; // 104743
                return 0;
            }
        }
    }

    return 0; // limit was enough, so we never reach here
}
