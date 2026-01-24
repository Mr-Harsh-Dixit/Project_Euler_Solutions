def read_cipher(path: str) -> list[int]:
    with open(path, "r", encoding="utf-8") as f:
        return [int(x) for x in f.read().strip().split(",")]

def is_printable_ascii(x: int) -> bool:
    # allow newline (10) and standard printable range
    return x == 10 or 32 <= x <= 126

def score_english(text: str) -> int:
    # crude but effective for this dataset
    common = [" the ", " and ", " of ", " to ", " in ", " that ", " is ", " was "]
    t = " " + text.lower() + " "
    return sum(t.count(w) for w in common)

def euler_59(path="0059_cipher.txt") -> tuple[str, int]:
    cipher = read_cipher(path)

    best_score = -1
    best_key = ""
    best_plain = ""

    for a in range(ord('a'), ord('z') + 1):
        for b in range(ord('a'), ord('z') + 1):
            for c in range(ord('a'), ord('z') + 1):
                key = [a, b, c]
                plain = []
                ok = True

                for i, val in enumerate(cipher):
                    p = val ^ key[i % 3]
                    if not is_printable_ascii(p):
                        ok = False
                        break
                    plain.append(p)

                if not ok:
                    continue

                text = "".join(chr(x) for x in plain)
                s = score_english(text)

                if s > best_score:
                    best_score = s
                    best_key = "".join(chr(x) for x in key)
                    best_plain = text

    ascii_sum = sum(ord(ch) for ch in best_plain)
    return best_key, ascii_sum

if __name__ == "__main__":
    key, total = euler_59()
    print(key, total)  # god 129448 (with official file)
