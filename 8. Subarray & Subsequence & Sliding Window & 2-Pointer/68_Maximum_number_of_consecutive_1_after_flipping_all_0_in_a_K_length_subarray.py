'''
Q. Maximum number of consecutive 1s after flipping all 0s in a K length subarray

Given a binary array arr[] of length N, and an integer K, the task is to find the maximum number of consecutive ones after flipping all zero in a subarray of length K.

Input: arr[]= {0, 0, 1, 1, 1, 1, 0, 1, 1, 0}, K = 2
Output: 7 
Explanation:
On taking the subarray [6, 7] and flip zero to one we get 7 consecutive ones.

Input: arr[]= {0, 0, 1, 1, 0, 0, 0, 0}, K = 3
Output: 5 
Explanation:
On taking the subarray [4, 6] and flip zero to one we get 5 consecutive ones. 



Intuition:-------------------------------------
Try flipping each subarray of length K, and count the maximum stretch of 1s in the modified array.

We can use a sliding window approach to efficiently evaluate the effect of flipping any K-length subarray.

✅ Approach:
1. Loop over all subarrays of length K.
2. For each subarray:
    a. Temporarily flip 0s to 1s in that subarray.
    b. Count the maximum number of consecutive 1s in the modified array.
    c. Keep track of the maximum of all such counts.
3. Return that maximum.
'''


def brute_maxConsecutiveOnesAfterFlipping(arr, K):
    # Time complexity: O(n^2)
    # Space complexity: O(n)
    n = len(arr)
    max_consecutive = 0
    for i in range(n - K + 1):
        # Make a copy and flip 0s in the subarray [i:i+K]
        temp = arr[:]
        for j in range(i, i + K):
            temp[j] = 1  # Flip 0s to 1s

        # Count maximum consecutive 1s in the temp array
        count = 0
        max_count = 0
        for val in temp:
            if val == 1:
                count += 1
                max_count = max(max_count, count)
            else:
                count = 0

        max_consecutive = max(max_consecutive, max_count)

    return max_consecutive






arr=[0, 0, 1, 1, 1, 1, 0, 1, 1, 0]
k=2

# arr=[0, 0, 1, 1, 0, 0, 0, 0]
# k=3

# Brute Soln
print(brute_maxConsecutiveOnesAfterFlipping(arr, k))

