from itertools import permutations

def euler_68() -> str:
    nums = set(range(1, 11))
    best = ""

    # choose internal cycle as permutation of 5 numbers from 1..10
    for inner in permutations(range(1, 11), 5):
        if 10 in inner:
            continue  # need 10 external for 16-digit result

        I = inner
        # We will try all possible E0 from remaining numbers
        remaining = list(nums - set(I))
        for E0 in remaining:
            S = E0 + I[0] + I[1]
            E = [0] * 5
            E[0] = E0
            ok = True
            usedE = {E0}

            for k in range(1, 5):
                ek = S - I[k] - I[(k + 1) % 5]
                if ek < 1 or ek > 10:
                    ok = False
                    break
                if ek in I or ek in usedE:
                    ok = False
                    break
                usedE.add(ek)
                E[k] = ek

            if not ok:
                continue

            # must use exactly 5 externals, and include 10
            if len(usedE) != 5 or 10 not in usedE:
                continue

            # build the 5 triplets (E[k], I[k], I[k+1])
            triplets = [(E[k], I[k], I[(k + 1) % 5]) for k in range(5)]

            # rotate so smallest external starts
            min_idx = min(range(5), key=lambda idx: triplets[idx][0])
            triplets = triplets[min_idx:] + triplets[:min_idx]

            s = "".join(f"{a}{b}{c}" for a, b, c in triplets)
            if len(s) == 16 and s > best:
                best = s

    return best

if __name__ == "__main__":
    print(euler_68())  # 6531031914842725
