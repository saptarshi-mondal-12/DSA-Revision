'''
Maximum Frequency After Subarray Operation

You are given an array nums of length n. You are also given an integer k.
You perform the following operation on nums once:
    Select a subarray nums[i..j] where 0 <= i <= j <= n - 1.
    Select an integer x and add x to all the elements in nums[i..j].
Find the maximum frequency of the value k after the operation.

 

Input: nums = [1,2,3,4,5,6], k = 1
Output: 2
Explanation:After adding -5 to nums[2..5], 1 has a frequency of 2 in [1, 2, -2, -1, 0, 1].


Input: nums = [10,2,3,4,5,5,4,3,2,2], k = 10
Output: 4
Explanation:After adding 8 to nums[1..9], 10 has a frequency of 4 in [10, 10, 11, 12, 13, 13, 12, 11, 10, 10].
'''

def maxFrequency(nums, k):
    result=nums.count(k)
    max_additional_freq = 0
        
    # Iterate through all unique elements in the array
    for target in set(nums):
        current_freq = 0
        max_freq = 0
            
        # Calculate the maximum subarray frequency for the current target
        for num in nums:
            if num == k:
                current_freq -= 1
            if num == target:
                current_freq += 1
            if current_freq < 0:
                current_freq = 0
            max_freq = max(max_freq, current_freq)
        max_additional_freq = max(max_additional_freq, max_freq)
        
    return result + max_additional_freq

print(maxFrequency([10,2,3,4,5,5,4,3,2,2], 10))