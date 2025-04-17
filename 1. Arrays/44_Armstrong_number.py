'''
Armstrong number

You are given a 3-digit number n, Find whether it is an Armstrong number or not.
An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371. 
Note: Return true if it is an Armstrong number else return false.

Input: n = 153
Output: true
Explanation: 153 is an Armstrong number since 13 + 53 + 33 = 153. 

Input: n = 372
Output: false
Explanation: 372 is not an Armstrong number since 33 + 73 + 23 = 378. 
'''

def armstrongNumber (n):
    s=0
    temp=n
    while(n!=0):
        r=n%10 
        s=s+(r*r*r)
        n=n//10 
    if s==temp:
        return("Yes")
    else:
        return("No")
print(armstrongNumber(121))