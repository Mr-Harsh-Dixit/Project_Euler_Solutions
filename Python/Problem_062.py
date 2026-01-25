def euler_62() -> int:
    digits_len = 1
    while True:
        seen = {}  # sig -> [count, smallest_cube]
        n = 1

        # Move n up until cube has digits_len digits
        while len(str(n**3)) < digits_len:
            n += 1

        # Process all n where cube has exactly digits_len digits
        while True:
            c = n * n * n
            s = str(c)
            if len(s) > digits_len:
                break

            sig = "".join(sorted(s))
            if sig in seen:
                seen[sig][0] += 1
            else:
                seen[sig] = [1, c]  # first cube is smallest by increasing n

            n += 1

        # Check if any signature reached exactly 5 in this digit-length block
        best = None
        for count, smallest in seen.values():
            if count == 5:
                if best is None or smallest < best:
                    best = smallest

        if best is not None:
            return best

        digits_len += 1

if __name__ == "__main__":
    print(euler_62())  # 127035954683
