'''
Q. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.

 
Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

'''
from functools import cmp_to_key
def compare(a, b):
    # (a then b)
    if a + b > b + a:
        return -1 

    # (b then a)
    elif a + b < b + a:
        return 1

    else:
        return 0
    
def largestNumber(nums):
    # Time Complexity: O(nlogn)
    # Space Complexity: O(n+S)
        
    # Step 1: Convert numbers to strings
    num_strings = [str(num) for num in nums]
        
    # Step 2: Sort with custom comparator
    num_strings.sort(key=cmp_to_key(compare))


    # print(num_strings)
        
    # Step 3: Edge case - if the largest number is '0', the whole number is 0
    if num_strings[0] == '0':
        return '0'
        
    # Step 4: Join and return
    return ''.join(num_strings)


# ALTERNATE SOLN  = num_strings.sort(key=lambda a: a * 10, reverse=True)
'''
Compare '3333333333' vs '30303030303030303030':
'3333333333' is lexicographically greater than '30303030303030303030', so '3' comes before '30' in the sorted list.

Compare '34343434343434343434' vs '30303030303030303030':
'34343434343434343434' is lexicographically greater than '30303030303030303030', so '34' comes before '30' in the sorted list.

Compare '5555555555' vs '3333333333':
'5555555555' is lexicographically greater than '3333333333', so '5' comes before '3'.

Compare '9999999999' vs '5555555555':
'9999999999' is lexicographically greater than '5555555555', so '9' comes before '5'.

# Sort strings based on concatenated values
# num_strings.sort(key=lambda a: a * 10, reverse=True)
'''





nums=[3,30,34,5,9]
print(largestNumber(nums))