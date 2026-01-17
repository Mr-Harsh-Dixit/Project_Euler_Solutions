def solve() -> int:
    s = set()
    for a in range(2, 101):
        for b in range(2, 101):
            s.add(pow(a, b))
    return len(s)

if __name__ == "__main__":
    print(solve())  # 9183
