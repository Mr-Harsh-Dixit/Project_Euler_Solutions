from math import comb

def u(n: int) -> int:
    s = 0
    sign = 1
    p = 1
    for _ in range(11):  # 0..10
        s += sign * p
        sign = -sign
        p *= n
    return s

def solve() -> int:
    vals = [0] + [u(n) for n in range(1, 12)]  # index 1..11
    ans = 0

    for k in range(1, 11):
        diff = [vals[i] for i in range(1, k + 1)]
        first_diffs = [diff[0]]

        for level in range(1, k):
            for i in range(k - level):
                diff[i] = diff[i + 1] - diff[i]
            first_diffs.append(diff[0])

        pred = sum(comb(k, j) * first_diffs[j] for j in range(k))
        if pred != vals[k + 1]:
            ans += pred

    return ans

if __name__ == "__main__":
    print(solve())  # 37076114526
