def name_value(name: str) -> int:
    return sum(ord(ch) - ord('A') + 1 for ch in name)

def solve_from_file(path: str = "names.txt") -> int:
    with open(path, "r", encoding="utf-8") as f:
        content = f.read().strip()

    names = [s.strip('"') for s in content.split(",")]
    names.sort()

    total = 0
    for i, name in enumerate(names, start=1):
        total += i * name_value(name)

    return total

if __name__ == "__main__":
    print(solve_from_file())  # 871198282
