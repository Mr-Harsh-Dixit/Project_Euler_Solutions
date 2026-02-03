from typing import List, Dict

def rule2_prefix_suffix(a: List[int]) -> bool:
    a = sorted(a)
    n = len(a)
    for k in range(1, n // 2 + 1):
        left = sum(a[:k+1])
        right = sum(a[-k:])
        if left <= right:
            return False
    return True

def rule1_disjoint(a: List[int]) -> bool:
    n = len(a)
    seen: Dict[int, int] = {}  # sum -> bitmask
    # pre-store a for speed
    for mask in range(1, 1 << n):
        s = 0
        m = mask
        idx = 0
        while m:
            if m & 1:
                s += a[idx]
            idx += 1
            m >>= 1

        prev = seen.get(s)
        if prev is None:
            seen[s] = mask
        else:
            if (prev & mask) == 0:  # disjoint subsets with equal sum
                return False
            # overlap: ignore
    return True

def is_special(a: List[int]) -> bool:
    return rule2_prefix_suffix(a) and rule1_disjoint(a)

def solve() -> str:
    best = [20, 31, 38, 39, 40, 42, 45]
    assert is_special(best)
    return "".join(str(x) for x in best)

if __name__ == "__main__":
    print(solve())  # 20313839404245
