def first_n_exceeding(m: int, target: int = 1_000_000) -> int:
    F = [1]  # F[0] = 1
    P = [1]  # P[0] = 1

    n = 0
    while F[n] <= target:
        n += 1
        if n < m:
            fn = 1
        else:
            fn = F[n - 1] + 1 + P[n - m - 1]
        F.append(fn)
        P.append(P[n - 1] + fn)

    return n

if __name__ == "__main__":
    print(first_n_exceeding(50))  # 168
