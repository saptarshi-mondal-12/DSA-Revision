'''
Find the Punishment Number of an Integer

Given a positive integer n, return the punishment number of n.
The punishment number of n is defined as the sum of the squares of all integers i such that:
1 <= i <= n The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.

Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182

Input: n = 37
Output: 1478
Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1. 
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
'''

class Solution:
    def can_partition(self, num, target):
        print(num, target)
        # Invalid partition found
        if target < 0 or num < target:
            return False

        # Valid partition found
        if num == target:
            return True

        # Recursively check all partitions for a valid partition
        return (
            self.can_partition(num // 10, target - num % 10)
            or self.can_partition(num // 100, target - num % 100)
            or self.can_partition(num // 1000, target - num % 1000)
        )

    def punishmentNumber(self, n: int) -> int:
        punishment_num = 0

        # Iterate through numbers in range [1, n]
        for current_num in range(1, n + 1):
            square_num = current_num * current_num

            # Check if valid partition can be found and add squared number if so
            if self.can_partition(square_num, current_num):
                punishment_num += square_num

        return punishment_num