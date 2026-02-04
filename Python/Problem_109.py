def solve():
    all_throws = []
    finishes = []

    # Singles, doubles, triples 1..20
    for v in range(1, 21):
        all_throws.append(v)        # S
        all_throws.append(2*v)     # D
        all_throws.append(3*v)     # T
        finishes.append(2*v)       # D only for finish

    # Bulls
    all_throws.append(25)          # S25
    all_throws.append(50)          # D25
    finishes.append(50)

    all_throws.sort()

    ans = 0

    for f in finishes:
        if f < 100:
            ans += 1

        for i in range(len(all_throws)):
            a = all_throws[i]
            if a + f < 100:
                ans += 1
            else:
                continue

            for j in range(i, len(all_throws)):
                b = all_throws[j]
                if a + b + f < 100:
                    ans += 1

    return ans

if __name__ == "__main__":
    print(solve())  # 38182
