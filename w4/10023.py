# run time : 1.300

# c = int(input())

# for i in range(c) :
#     n = input()
#     n = int(input())

#     if (i > 0) :
#         print('')

#     x = 11
#     y = n

#     while (abs(y - x) > 0.001) :
#         x = (x + y) // 2
#         y = n // x

#     print(x)

#####

# run time : 0.330

from decimal import Decimal, getcontext
getcontext().prec = 1000

t = int(input())
for i in range(t) :
    input()
    if i :
        print()
    print(int(int(Decimal(input()))**Decimal(0.5)))