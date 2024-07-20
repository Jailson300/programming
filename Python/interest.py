p = int(input("Enter the Amount: "))
r = float(input("Enter interest rate: "))
n = 4
t = int(input("Enter the number of years: "))

amount= p * ((1 + r / n)**(n * t))
print("The balance after",t,"years is Rs. ",amount)