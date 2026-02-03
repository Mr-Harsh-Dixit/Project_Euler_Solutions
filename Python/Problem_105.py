def rule2_quick(a):
    a = sorted(a)
    n = len(a)
    # prefix sums for speed
    pref = [0]
    for x in a:
        pref.append(pref[-1] + x)

    for k in range(1, n // 2 + 1):
        left = pref[k + 1]              # a1..a(k+1)
        right = sum(a[-k:])             # largest k
        if left <= right:
            return False
    return True

def rule1_disjoint(a):
    n = len(a)
    seen = {}  # sum -> bitmask
    for mask in range(1, 1 << n):
        s = 0
        m = mask
        i = 0
        while m:
            if m & 1:
                s += a[i]
            i += 1
            m >>= 1

        prev = seen.get(s)
        if prev is None:
            seen[s] = mask
        else:
            if (prev & mask) == 0:  # disjoint subsets with equal sum
                return False
    return True

def is_special(a):
    a = sorted(a)
    return rule2_quick(a) and rule1_disjoint(a)

def solve(path="sets.txt"):
    ans = 0
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            a = list(map(int, line.strip().split(",")))
            if is_special(a):
                ans += sum(a)
    return ans

if __name__ == "__main__":
    print(solve("sets.txt"))  # 73702 
