def euler_65() -> int:
    # build coefficients for e
    a = [0] * 100
    a[0] = 2
    for i in range(1, 100):
        if i % 3 == 2:
            a[i] = 2 * ((i + 1) // 3)
        else:
            a[i] = 1

    # convergent recurrence
    p_prev = 0
    p_curr = 1

    for i in range(100):
        p_next = a[i] * p_curr + p_prev
        p_prev, p_curr = p_curr, p_next

    # p_curr is numerator of 100th convergent
    return sum(int(c) for c in str(p_curr))

if __name__ == "__main__":
    print(euler_65())  # 272
