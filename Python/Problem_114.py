def solve(n=50):
    F = [0] * (n + 1)
    F[0] = 1

    for i in range(1, n + 1):
        # Leading grey
        F[i] = F[i - 1]

        # Red block of length k >= 3, followed by grey
        for k in range(3, i):
            F[i] += F[i - k - 1]

        # Red block exactly to the end
        if i >= 3:
            F[i] += 1

    return F[n]

if __name__ == "__main__":
    print(solve(50))  # 16475640049
