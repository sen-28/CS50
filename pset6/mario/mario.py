from cs50 import get_int
while True:
    n = get_int("Height: ")
    if (n <= 8 and n >= 1):
        break
for i in range(n):
    j = i + 1
    print (" "*(n - j) + "#"*j + " " + "#"*j)