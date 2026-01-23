from collections import Counter

RVAL = {**{str(i): i for i in range(2, 10)},
        "T": 10, "J": 11, "Q": 12, "K": 13, "A": 14}

def score(hand):
    # hand: list like ["5H","5C","6S","7S","KD"]
    ranks = sorted(RVAL[c[0]] for c in hand)
    suits = [c[1] for c in hand]

    is_flush = all(s == suits[0] for s in suits)

    # straight (handle A2345)
    is_straight = False
    straight_high = ranks[-1]
    if ranks == list(range(ranks[0], ranks[0] + 5)):
        is_straight = True
    elif ranks == [2, 3, 4, 5, 14]:
        is_straight = True
        straight_high = 5

    cnt = Counter(ranks)
    groups = sorted(((c, r) for r, c in cnt.items()), reverse=True)  # by count then rank

    ranks_desc = tuple(sorted(ranks, reverse=True))

    if is_flush and is_straight:
        if straight_high == 14:
            return (9,)  # royal flush
        return (8, straight_high)

    if groups[0][0] == 4:
        quad = groups[0][1]
        kicker = max(r for r in ranks if r != quad)
        return (7, quad, kicker)

    if groups[0][0] == 3 and groups[1][0] == 2:
        trip = groups[0][1]
        pair = groups[1][1]
        return (6, trip, pair)

    if is_flush:
        return (5,) + ranks_desc

    if is_straight:
        return (4, straight_high)

    if groups[0][0] == 3:
        trip = groups[0][1]
        kickers = tuple(sorted((r for r in ranks if r != trip), reverse=True))
        return (3, trip) + kickers

    if groups[0][0] == 2 and groups[1][0] == 2:
        pair1, pair2 = groups[0][1], groups[1][1]
        high_pair, low_pair = max(pair1, pair2), min(pair1, pair2)
        kicker = max(r for r in ranks if r != pair1 and r != pair2)
        return (2, high_pair, low_pair, kicker)

    if groups[0][0] == 2:
        pair = groups[0][1]
        kickers = tuple(sorted((r for r in ranks if r != pair), reverse=True))
        return (1, pair) + kickers

    return (0,) + ranks_desc


def euler_54(path="poker.txt") -> int:
    wins = 0
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            cards = line.strip().split()
            h1, h2 = cards[:5], cards[5:]
            if score(h1) > score(h2):
                wins += 1
    return wins


if __name__ == "__main__":
    print(euler_54())  # should print 376 with the official dataset
