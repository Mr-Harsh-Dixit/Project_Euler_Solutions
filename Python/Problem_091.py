import math

def max_steps(x, y, dx, dy, N):
    INF = 10**18
    lim = INF
    if dx > 0: lim = min(lim, (N - x) // dx)
    elif dx < 0: lim = min(lim, x // (-dx))
    if dy > 0: lim = min(lim, (N - y) // dy)
    elif dy < 0: lim = min(lim, y // (-dy))
    return 0 if lim == INF else lim

def euler_91(N=50):
    ans = N * N  # right angle at origin
    for x in range(N + 1):
        for y in range(N + 1):
            if x == 0 and y == 0:
                continue
            g = math.gcd(x, y)
            dx = -y // g
            dy =  x // g
            ans += max_steps(x, y, dx, dy, N)
            ans += max_steps(x, y, -dx, -dy, N)
    return ans

if __name__ == "__main__":
    print(euler_91(50))  # 14234
