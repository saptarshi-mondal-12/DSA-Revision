'''
Q. Reordered Power of 2

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Input: n = 1
Output: true

Input: n = 10
Output: false
'''

def reorderedPowerOf2(n):
    sortedPowers = [ # sorted powers
        "1", "2", "4", "8", "16", "23", "46", "128", "256", "125",
        "0124", "0248", "0469", "1289", "13468", "23678", "35566",
        "011237", "122446", "224588", "0145678", "0122579", 
        "0134449", "0368888", "11266777", "23334455", "01466788",
        "112234778", "234455668", "012356789", "0112344778",
        "1234446788", "2244667999", "2345588999"
    ]
    
    s = ''.join(sorted(str(n)))

    if s in sortedPowers:
        return True
    return False

print(reorderedPowerOf2(64))