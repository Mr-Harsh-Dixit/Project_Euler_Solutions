def is_pandigital_1_to_9(a: int, b: int, p: int) -> bool:
    s = f"{a}{b}{p}"
    if len(s) != 9:
        return False
    if '0' in s:
        return False
    return len(set(s)) == 9  # must be 1..9 exactly once

def solve() -> int:
    prods = set()

    # 1-digit × 4-digit = 4-digit
    for a in range(1, 10):
        for b in range(1234, 9877):
            p = a * b
            if 1000 <= p <= 9999 and is_pandigital_1_to_9(a, b, p):
                prods.add(p)

    # 2-digit × 3-digit = 4-digit
    for a in range(12, 99):
        for b in range(123, 988):
            p = a * b
            if 1000 <= p <= 9999 and is_pandigital_1_to_9(a, b, p):
                prods.add(p)

    return sum(prods)

if __name__ == "__main__":
    print(solve())  # 45228
