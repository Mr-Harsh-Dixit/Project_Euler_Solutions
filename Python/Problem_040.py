def digit_at(k: int) -> int:
    length = 1
    count = 9
    start = 1

    while k > length * count:
        k -= length * count
        length += 1
        count *= 10
        start *= 10

    index, offset = divmod(k - 1, length)
    num = start + index
    return int(str(num)[offset])

def solve() -> int:
    ans = 1
    for p in (1, 10, 100, 1000, 10000, 100000, 1000000):
        ans *= digit_at(p)
    return ans

if __name__ == "__main__":
    print(solve())  # 210
