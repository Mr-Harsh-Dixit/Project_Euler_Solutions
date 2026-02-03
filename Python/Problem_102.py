def cross(ax: int, ay: int, bx: int, by: int) -> int:
    return ax * by - ay * bx

def contains_origin(x1, y1, x2, y2, x3, y3) -> bool:
    s1 = cross(x2 - x1, y2 - y1, -x1, -y1)
    s2 = cross(x3 - x2, y3 - y2, -x2, -y2)
    s3 = cross(x1 - x3, y1 - y3, -x3, -y3)

    # Strict interior: reject edge cases
    if s1 == 0 or s2 == 0 or s3 == 0:
        return False

    has_pos = (s1 > 0) or (s2 > 0) or (s3 > 0)
    has_neg = (s1 < 0) or (s2 < 0) or (s3 < 0)
    return not (has_pos and has_neg)

def solve(path: str) -> int:
    cnt = 0
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            parts = line.strip().split(",")
            if not parts or len(parts) != 6:
                continue
            x1, y1, x2, y2, x3, y3 = map(int, parts)
            if contains_origin(x1, y1, x2, y2, x3, y3):
                cnt += 1
    return cnt

if __name__ == "__main__":
    print(solve("triangles.txt"))
