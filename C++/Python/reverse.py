def reverse(str):
    rev = ""
    for c in str:
        rev = c + rev
    return rev
str =  input("Enter a word: ")
print("the reverse string of ",str," is ",reverse(str))