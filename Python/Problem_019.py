def is_leap(year: int) -> bool:
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    return year % 4 == 0


def days_in_month(year: int, month: int) -> int:
    if month in (4, 6, 9, 11):
        return 30
    if month == 2:
        return 29 if is_leap(year) else 28
    return 31


def solve() -> int:
    # 0=Mon,1=Tue,...,6=Sun
    weekday = 0  # 1 Jan 1900 is Monday
    count = 0

    for year in range(1900, 2001):
        for month in range(1, 13):
            if year >= 1901 and weekday == 6:
                count += 1
            weekday = (weekday + days_in_month(year, month)) % 7

    return count


if __name__ == "__main__":
    print(solve())  # 171
