def word_value(w: str) -> int:
    return sum(ord(c) - ord('A') + 1 for c in w)

def solve(path: str = "words.txt") -> int:
    with open(path, "r", encoding="utf-8") as f:
        data = f.read().strip()

    words = [w.strip('"') for w in data.split(",")]

    values = [word_value(w) for w in words]
    max_val = max(values)

    triangles = set()
    n = 1
    while (t := n * (n + 1) // 2) <= max_val:
        triangles.add(t)
        n += 1

    return sum(1 for v in values if v in triangles)

if __name__ == "__main__":
    print(solve())  # 162 for Project Euler words.txt
