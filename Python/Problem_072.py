def euler_72(N: int = 1_000_000) -> int:
    phi = list(range(N + 1))
    for i in range(2, N + 1):
        if phi[i] == i:  # prime
            for j in range(i, N + 1, i):
                phi[j] -= phi[j] // i
    return sum(phi[2:])

if __name__ == "__main__":
    print(euler_72())  # 303963552391
