from cs50 import get_int
num = get_int("Number: ")

n = num
even = 0
odd = 0
while True:
    even += n % 10
    n = int(n / 10)

    if n == 0:
        break
    if len(str(n)) == 2:
        twodig = n
    if len(str(n)) == 1:
        onedig = n

    m = (n %  10)*2
    odd += m % 10
    odd += int(m / 10)
    n = int(n / 10)

    if n == 0:
        break
    if len(str(n)) == 2:
        twodig = n
    if len(str(n)) == 1:
        onedig = n

if ((even + odd) % 10) == 0:
    if (len(str(num)) == 15 and twodig in [34, 37]):
        print("AMEX")
    elif (len(str(num)) == 16 and twodig in [51, 52, 53, 54, 55]):
        print("MASTERCARD")
    elif (len(str(num)) in [13, 16]  and onedig == 4):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")



