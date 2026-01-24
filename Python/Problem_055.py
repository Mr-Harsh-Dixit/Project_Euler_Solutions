def is_palindrome_str(s: str) -> bool:
    return s == s[::-1]

def reverse_int(x: int) -> int:
    return int(str(x)[::-1])

def is_lychrel(n: int, max_iter: int = 50) -> bool:
    x = n
    for _ in range(max_iter):
        x += reverse_int(x)
        if is_palindrome_str(str(x)):
            return False
    return True

def euler_55() -> int:
    return sum(1 for n in range(1, 10_000) if is_lychrel(n))

if __name__ == "__main__":
    print(euler_55())  # 249
