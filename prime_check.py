def primeCheck(num):
    if num < 2:
        return False
    for i in range (2, num // 2  + 1 ):
        if num % 2 == 0:
            return False
    return True
num  = int(input("Enter a number: "))
if primeCheck(num):
    print(num," is a prime number")
else:
    print(num," is not a prime number")