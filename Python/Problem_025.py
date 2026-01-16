def solve() -> int:
    a, b = 1, 1  # F1, F2
    idx = 2

    while len(str(b)) < 1000:
        a, b = b, a + b
        idx += 1

    return idx

if __name__ == "__main__":
    print(solve())  # 4782
