def solve() -> int:
    ones = {
        0: 0,
        1: 3,  # one
        2: 3,  # two
        3: 5,  # three
        4: 4,  # four
        5: 4,  # five
        6: 3,  # six
        7: 5,  # seven
        8: 5,  # eight
        9: 4,  # nine
    }

    teens = {
        10: 3,  # ten
        11: 6,  # eleven
        12: 6,  # twelve
        13: 8,  # thirteen
        14: 8,  # fourteen
        15: 7,  # fifteen
        16: 7,  # sixteen
        17: 9,  # seventeen
        18: 8,  # eighteen
        19: 8,  # nineteen
    }

    tens = {
        2: 6,  # twenty
        3: 6,  # thirty
        4: 5,  # forty
        5: 5,  # fifty
        6: 5,  # sixty
        7: 7,  # seventy
        8: 6,  # eighty
        9: 6,  # ninety
    }

    HUNDRED = 7   # "hundred"
    AND = 3       # "and"
    THOUSAND = 8  # "thousand"

    def letters(n: int) -> int:
        if n == 1000:
            return ones[1] + THOUSAND

        total = 0

        if n >= 100:
            h = n // 100
            total += ones[h] + HUNDRED
            if n % 100 != 0:
                total += AND
            n %= 100

        if n >= 20:
            total += tens[n // 10]
            total += ones[n % 10]
        elif n >= 10:
            total += teens[n]
        else:
            total += ones[n]

        return total

    return sum(letters(i) for i in range(1, 1001))


if __name__ == "__main__":
    print(solve())  # 21124
