def sieve(n: int) -> bytearray:
    is_prime = bytearray(b"\x01") * (n + 1)
    if n >= 0:
        is_prime[0] = 0
    if n >= 1:
        is_prime[1] = 0

    import math
    r = int(math.isqrt(n))
    for i in range(2, r + 1):
        if is_prime[i]:
            start = i * i
            step = i
            is_prime[start:n + 1:step] = b"\x00" * (((n - start) // step) + 1)
    return is_prime


def euler_51(limit: int = 2_000_000) -> int:
    is_prime = sieve(limit)

    for p in range(2, limit + 1):
        if not is_prime[p]:
            continue

        s = str(p)
        L = len(s)

        for d in "0123456789":
            pos = [i for i, ch in enumerate(s) if ch == d and i != L - 1]
            k = len(pos)
            if k == 0:
                continue

            for mask in range(1, 1 << k):
                idxs = [pos[j] for j in range(k) if (mask >> j) & 1]

                chars = list(s)
                for i in idxs:
                    chars[i] = "*"
                pattern = "".join(chars)

                cnt = 0
                smallest = None
                leading = 0 in idxs

                for r in "0123456789":
                    if leading and r == "0":
                        continue
                    cand = int(pattern.replace("*", r))
                    if cand <= limit and is_prime[cand]:
                        cnt += 1
                        if smallest is None:
                            smallest = cand
                        if cnt > 8:  # tiny prune
                            break

                if cnt == 8 and smallest == p:
                    return p

    raise ValueError("Not found within limit; increase limit.")


if __name__ == "__main__":
    print(euler_51())  # 121313
