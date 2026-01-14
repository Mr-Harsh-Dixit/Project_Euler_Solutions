def nCr(n: int, r: int) -> int:
    r = min(r, n - r)
    result = 1
    for i in range(1, r + 1):
        result = result * (n - r + i) // i
    return result

if __name__ == "__main__":
    print(nCr(40, 20))  # 137846528820
