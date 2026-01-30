def roman_to_int(s: str) -> int:
    val = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
    total = 0
    for i in range(len(s)):
        if i+1 < len(s) and val[s[i]] < val[s[i+1]]:
            total -= val[s[i]]
        else:
            total += val[s[i]]
    return total

def int_to_roman(n: int) -> str:
    table = [
        (1000,"M"),(900,"CM"),(500,"D"),(400,"CD"),
        (100,"C"),(90,"XC"),(50,"L"),(40,"XL"),
        (10,"X"),(9,"IX"),(5,"V"),(4,"IV"),(1,"I")
    ]
    res = []
    for v,s in table:
        while n >= v:
            res.append(s)
            n -= v
    return "".join(res)

def euler_89(path="roman.txt"):
    saved = 0
    with open(path) as f:
        for line in f:
            r = line.strip()
            v = roman_to_int(r)
            m = int_to_roman(v)
            saved += len(r) - len(m)
    return saved

if __name__ == "__main__":
    print(euler_89())  # 743
