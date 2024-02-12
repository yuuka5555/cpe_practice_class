import math

while True :
    try:
        a, b, c = input().split()
        a = int(a)
        b = int(b)
        c = int(c)

        ans = 0
        if a != 1 and b % c == 0 :
            if b == c :
                ans = 1
            elif (b - c) * math.log(a, 10) + 1 < 100 :
                ans = (a ** b - 1) // (a ** c - 1)
        
        print(f"({a}^{b}-1)/({a}^{c}-1) ", end="")

        if ans :
            print(ans)
        else :
            print("is not an integer with less than 100 digits.")
    except EOFError :
        break