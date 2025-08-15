'''
Q. Swap two numbers without using a third variable
'''

def swap(a, b):
    print("Before: a=", a, "b=",b)

    a = a + b;  # a becomes 15
    b = a - b;  # b becomes 5
    a = a - b;  # a becomes 10

    print("After: a=", a, "b=",b)


a=5
b=10
swap(a,b)