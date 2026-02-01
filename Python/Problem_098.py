def solve_euler98(path="words.txt"):
    # --- helpers ---
    def pat(s: str) -> tuple:
        mp = {}
        out = []
        nxt = 0
        for ch in s:
            if ch not in mp:
                mp[ch] = nxt
                nxt += 1
            out.append(mp[ch])
        return tuple(out)

    def build_map(word: str, num: str):
        # letter->digit and digit->letter bijection
        l2d = {}
        d2l = {}
        for ch, dg in zip(word, num):
            if ch in l2d and l2d[ch] != dg:
                return None
            if dg in d2l and d2l[dg] != ch:
                return None
            l2d[ch] = dg
            d2l[dg] = ch
        if l2d[word[0]] == '0':  # leading zero not allowed
            return None
        return l2d

    def apply_map(word: str, l2d):
        return "".join(l2d[ch] for ch in word)

    # --- read words ---
    with open(path, "r") as f:
        raw = f.read().strip()
    words = raw.replace('"', "").split(",")

    # --- group anagrams ---
    from collections import defaultdict
    groups = defaultdict(list)
    for w in words:
        groups["".join(sorted(w))].append(w)

    # --- precompute squares by length on demand ---
    squares_list = {}
    squares_set = {}

    def ensure_squares(L: int):
        if L in squares_list:
            return
        lo = 10 ** (L - 1)
        hi = 10 ** L - 1
        import math
        a = int(math.isqrt(lo))
        if a * a < lo:
            a += 1
        b = int(math.isqrt(hi))
        lst = []
        st = set()
        for x in range(a, b + 1):
            s = str(x * x)
            lst.append(s)
            st.add(s)
        squares_list[L] = lst
        squares_set[L] = st

    best = 0

    # --- test pairs ---
    for ws in groups.values():
        if len(ws) < 2:
            continue
        # avoid palindromic "anagram of itself" nonsense by using pairs only
        for i in range(len(ws)):
            for j in range(i + 1, len(ws)):
                a, b = ws[i], ws[j]
                if len(a) != len(b):
                    continue
                L = len(a)
                ensure_squares(L)

                pa = pat(a)
                pb = pat(b)

                # For each candidate square for 'a'
                for sq in squares_list[L]:
                    if pat(sq) != pa:
                        continue
                    m = build_map(a, sq)
                    if m is None:
                        continue

                    other = apply_map(b, m)
                    if other[0] == '0':
                        continue
                    if other in squares_set[L] and pat(other) == pb:
                        best = max(best, int(sq), int(other))

    return best

if __name__ == "__main__":
    print(solve_euler98("words.txt"))  # 18769
