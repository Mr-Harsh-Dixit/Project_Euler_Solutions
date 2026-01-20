def is_pandigital_1_to_9(s: str) -> bool:
    return len(s) == 9 and '0' not in s and len(set(s)) == 9

def solve() -> int:
    best = 0
    for x in range(9876, 9122, -1):
        s = str(x) + str(2 * x)
        if is_pandigital_1_to_9(s):
            best = int(s)
            break  # descending, first hit is maximum
    return best

if __name__ == "__main__":
    print(solve())  # 932718654
