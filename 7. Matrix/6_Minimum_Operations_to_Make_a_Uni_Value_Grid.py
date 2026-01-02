'''
Q. Minimum Operations to Make a Uni-Value Grid

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.


Input: grid = [[2,4],[6,8]], x = 2
-----
2 | 4
-----
6 | 8
-----
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.

Input: grid = [[1,5],[2,3]], x = 1
------
1 | 5
------
2 | 3
------
Output: 5
Explanation: We can make every element equal to 3.


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.


--------------------Intuition----------------------------------------------------------------
Brute Intuition: 

check for each no present in the grid -> try to convert equivalent to it, whichever gives minimum no of operation return ans,
For example, given grid = [[2, 4], [6, 8]] and x = 2, we can make all elements equal to 10 in 4 + 3 + 2 + 1 = 10 operations. However, this is not optimal because, along the way, we reached a state where all elements were equal to 8 in just 3 + 2 + 1 = 6 operations (not the best, but still better). same check for all other elements present in grid. 



Optimal Intuition: 

We are given a 2D integer array grid, a number x, and the ability to add or subtract x from any element in the grid any number of times. Our goal is to determine the smallest number of such operations needed to make all elements in the grid equal. If it is impossible to achieve this, we return -1.

We can see that if it is possible to make all elements equal, the optimal final value must be one of the original numbers in the grid, as any other value may require unnecessary extra steps.

For example, given grid = [[2, 4], [6, 8]] and x = 2, we can make all elements equal to 10 in 4 + 3 + 2 + 1 = 10 operations. However, this is not optimal because, along the way, we reached a state where all elements were equal to 8 in just 3 + 2 + 1 = 6 operations (not the best, but still better). From that point, increasing all numbers by 2 again is unnecessary.

Approach 1: Sorting and Median 2 7

First, let's think about when it's possible to make all grid elements equal.
Consider any two numbers in the grid, a and b, and a number x. Suppose we want to make both a and b equal to some value v. The only operation allowed is adding or subtracting x some number of times. This means we must be able to reach v from both a and b using x.
For this to be possible, the differences v - a and v - b must both be multiples of x, or equivalently:

(v-a)%x=0 and (v-b)%x=0

Rearranging this, we get:

a%x=b%x=v%x

This tells us that all numbers in the grid must have the same remainder when divided by x. Otherwise, it is impossible to transform them into a single value using only x-sized steps.

For example, if grid = [[1, 8], [3, 5]] and x = 2, we cannot make all elements equal to any odd value because 8 is even, and adding 2 any number of times will always result in an even number. Similarly, we cannot make all elements equal to any even value because 1, 3, and 5 are odd, and adding 2 will always keep them odd. Since we cannot make all numbers have the same parity, it is impossible to make the grid uni-value.

Thus, our first step is to check if all numbers in the grid have the same remainder when divided by x. If they don't, we immediately return -1. Otherwise, our goal is to find the smallest number of operations required.

To make things easier, note that the arrangement of numbers in the grid doesn’t affect our task at all, since we can apply operations to any number, no matter its position. So, we can simplify the problem by flattening the grid into a one-dimensional array.

Now, which value should we aim to make all numbers equal to?

If we pick a value too large, then the smaller numbers will need many additions of x to reach it.
If we pick a value too small, then the larger numbers will need many subtractions of x.
A natural choice is the median of the numbers.

Why? The median is the balancing point that minimizes the total distance numbers need to move. By choosing the median, we ensure that half of the numbers shift up and the other half shift down, naturally minimizing the total number of operations.
For example, consider grid = [[2, 4], [6, 8]] with x = 2:

If we make all values 8, we need 3 + 2 + 1 + 0 = 6 operations.
If we choose 4 (the median), the operations reduce to 1 + 0 + 1 + 2 = 4.
In fact, selecting the median of the numbers always results in the smallest number of operations.

To find the median, we first sort the array in non-decreasing order and then pick the middle value. Next, we iterate through the array again to calculate how many operations are needed for each number to reach the median, and then we sum these operations.
'''

def minOperations(grid, x):
    # Time complexity: O(mn×logmn) 
    # First, we loop through the grid’s elements to flatten it into a one-dimensional array, which takes O(m*n) time. Then, we sort the numsArray in O(mn*logmn), since it contains m*n elements. Finally, we go through the array, performing constant-time operations (arithmetic and checks) in each step, which takes another O(mn) time. Therefore, the overall time complexity is dominated by the sorting step and is equal to O(mn×logmn).

    # Space complexity: O(mn)


    # Create a list to store all the numbers from the grid
    nums_array = []
    result = 0

    # Flatten the grid into nums_array
    for row in grid:
        for num in row:
            nums_array.append(num)

    # Sort nums_array in non-decreasing order to easily find the median
    nums_array.sort()

    length = len(nums_array)
    # Store the median element as the final common value
    final_common_number = nums_array[length // 2]

    # Iterate through each number in nums_array
    for number in nums_array:
        # If the remainder when divided by x is different, return -1
        if number % x != final_common_number % x:
            return -1
        # Add the number of operations required to make the current number equal to final_common_number
        result += abs(final_common_number - number) // x
    return result


grid = [[2,4],[6,8]]
x = 2
print(minOperations(grid, x))
