'''
Minimized Maximum of Products Distributed to Any Store

You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.
You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.


Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

Input: n = 7, quantities = [15,10,10]
Output: 5
Explanation: One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.

Input: n = 1, quantities = [100000]
Output: 100000
Explanation: The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.
'''

def check(n, quantities, mid) -> bool:
    i=0
    remaining=quantities[i]
    for t in range(0,n):
        if remaining <= mid:
            i+=1
            if i==len(quantities):
                return True
            else:
                remaining=quantities[i]
        else:
            remaining-=mid
    return False


def minimizedMaximum(n, quantities) -> int:
    result=max(quantities)
    i=1
    j=max(quantities)
    while i <= j:
        mid=(i+j)//2
        if (check(n, quantities, mid)):
            result=min(result, mid)
            j=mid-1
        else:
            i=mid+1
    return result

# Time complexity: O(nlogk)
n = 6
quantities = [11,6]
print(minimizedMaximum(n, quantities))