from itertools import combinations

def expand69(s: set[int]) -> set[int]:
    if 6 in s or 9 in s:
        s = set(s)
        s.add(6)
        s.add(9)
    return s

def euler_90() -> int:
    digits = range(10)
    cubes = [set(c) for c in combinations(digits, 6)]

    req = [(0,1),(0,4),(0,9),(1,6),(2,5),(3,6),(4,9),(6,4),(8,1)]

    count = 0
    for i in range(len(cubes)):
        A = expand69(cubes[i])
        for j in range(i, len(cubes)):
            B = expand69(cubes[j])

            ok = True
            for x, y in req:
                if not ((x in A and y in B) or (y in A and x in B)):
                    ok = False
                    break
            if ok:
                count += 1
    return count

if __name__ == "__main__":
    print(euler_90())  # 1217
