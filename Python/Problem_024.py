import math

def solve() -> str:
    digits = list("0123456789")
    k = 1_000_000 - 1  # 0-based
    out = []

    for n in range(len(digits), 0, -1):
        f = math.factorial(n - 1)
        idx, k = divmod(k, f)
        out.append(digits.pop(idx))

    return "".join(out)

if __name__ == "__main__":
    print(solve())  # 2783915460
