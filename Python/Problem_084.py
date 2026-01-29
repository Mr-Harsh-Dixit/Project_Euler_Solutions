def euler_84_modal_string() -> str:
    N = 40
    SIDES = 4
    ST = N * 3
    JAIL = 10
    G2J = 30
    CC = {2, 17, 33}
    CH = {7, 22, 36}
    R = [5, 15, 25, 35]
    U = [12, 28]

    def to_id(pos: int, d: int) -> int:
        return pos * 3 + d

    def next_railway(pos: int) -> int:
        for r in R:
            if r > pos:
                return r
        return R[0]

    def next_utility(pos: int) -> int:
        for u in U:
            if u > pos:
                return u
        return U[0]

    # resolve special squares into a distribution over final positions
    def resolve(pos: int):
        # returns list of (final_pos, prob)
        if pos == G2J:
            return [(JAIL, 1.0)]

        if pos in CC:
            # 1/16 GO, 1/16 JAIL, else stay
            return [(0, 1/16), (JAIL, 1/16), (pos, 14/16)]

        if pos in CH:
            out = []
            # 10 movement cards, each 1/16
            out.append((0, 1/16))          # GO
            out.append((JAIL, 1/16))       # JAIL
            out.append((11, 1/16))         # C1
            out.append((24, 1/16))         # E3
            out.append((39, 1/16))         # H2
            out.append((5, 1/16))          # R1
            out.append((next_railway(pos), 1/16))  # next R
            out.append((next_railway(pos), 1/16))  # next R (second card)
            out.append((next_utility(pos), 1/16))  # next U

            back3 = (pos - 3) % 40
            # back 3 might land on CC (only happens from CH3=36 -> 33)
            if back3 in CC:
                for pp, pr in resolve(back3):
                    out.append((pp, (1/16) * pr))
            else:
                out.append((back3, 1/16))

            # remaining 6/16: no movement, stay on CH
            out.append((pos, 6/16))
            return out

        return [(pos, 1.0)]

    # Build sparse transitions: trans[s] = list of (t, prob)
    trans = [[] for _ in range(ST)]
    p_die = 1.0 / (SIDES * SIDES)

    for pos in range(N):
        for d in range(3):
            s = to_id(pos, d)
            acc = {}  # t -> prob
            for a in range(1, SIDES + 1):
                for b in range(1, SIDES + 1):
                    is_double = (a == b)
                    if is_double and d == 2:
                        t = to_id(JAIL, 0)
                        acc[t] = acc.get(t, 0.0) + p_die
                        continue

                    nd = (d + 1) if is_double else 0
                    np = (pos + a + b) % N

                    for fp, pr in resolve(np):
                        t = to_id(fp, nd if fp != JAIL else 0)
                        # (being sent to jail resets doubles count anyway)
                        acc[t] = acc.get(t, 0.0) + p_die * pr

            trans[s] = list(acc.items())

    # Power iteration to get stationary distribution
    v = [1.0 / ST] * ST
    for _ in range(2000):
        v2 = [0.0] * ST
        for s in range(ST):
            vs = v[s]
            if vs == 0.0:
                continue
            for t, pr in trans[s]:
                v2[t] += vs * pr
        diff = max(abs(v2[i] - v[i]) for i in range(ST))
        v = v2
        if diff < 1e-15:
            break

    # Aggregate by square
    sq = [0.0] * N
    for pos in range(N):
        sq[pos] = v[to_id(pos, 0)] + v[to_id(pos, 1)] + v[to_id(pos, 2)]

    top3 = sorted(range(N), key=lambda i: sq[i], reverse=True)[:3]
    return "".join(f"{x:02d}" for x in top3)

if __name__ == "__main__":
    print(euler_84_modal_string())  # 101524
