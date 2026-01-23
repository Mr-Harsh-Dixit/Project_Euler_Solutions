def signature(num: int) -> tuple[int, ...]:
    cnt = [0] * 10
    while num > 0:
        cnt[num % 10] += 1
        num //= 10
    return tuple(cnt)

def euler_52() -> int:
    n = 1
    while True:
        low = 10 ** (n - 1)
        high = (10 ** n - 1) // 6

        for x in range(low, high + 1):
            sig = signature(x)
            for k in range(2, 7):
                if signature(k * x) != sig:
                    break
            else:
                return x
        n += 1

if __name__ == "__main__":
    print(euler_52())  # 142857
