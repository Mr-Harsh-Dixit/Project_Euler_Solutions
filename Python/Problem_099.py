import math

def euler_99(path="base_exp.txt"):
    best_line = -1
    best_score = float("-inf")

    with open(path, "r") as f:
        for i, line in enumerate(f, start=1):
            b_str, e_str = line.strip().split(",")
            b = int(b_str)
            e = int(e_str)
            score = e * math.log(b)  # ln(b)
            if score > best_score:
                best_score = score
                best_line = i

    return best_line

if __name__ == "__main__":
    print(euler_99("base_exp.txt"))  # 709 for Euler dataset
