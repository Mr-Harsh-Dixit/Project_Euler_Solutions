def euler_100(limit=10**12):
    x, y = 41, 29  # n=21, b=15

    while (x + 1) // 2 <= limit:
        x, y = 3*x + 4*y, 2*x + 3*y

    b = (y + 1) // 2
    return b

if __name__ == "__main__":
    print(euler_100())  # 756872327473
