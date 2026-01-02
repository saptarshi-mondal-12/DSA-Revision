#include<bits/stdc++.h>
using namespace std;

/* Q. Kth Largest Element in an Array - Amazon 2025

Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

TRY : MATRIX FOLDER Q8. "Kth Smallest Element in a Sorted Matrix"
*/

int brute_findKthLargest(vector<int>& nums, int k) {
    // Time Complexity: O(NlogN)
    // Space Complexity: O(1)

    // Intution: Sort the array in ascending order and return the (n-k)th element.
    int n = nums.size();
    sort(nums.begin(),nums.end());
    return nums[n-k];   
}

int optimal_findKthLargest(vector<int>& nums, int k) {
    // Time Complexity: O(NlogK)
    // Space Complexity: O(K)

    // Intution: Use a min-heap of size k to keep track of the k largest elements. we push elements into the heap and if the size exceeds k, we pop the smallest element. At the end, the top of the heap will be the kth largest element.

    /* Dry Run:[3,2,1,5,6,4], k = 2
    pq.push(3) -> [3]
    pq.push(2) -> [2,3]
    pq.push(1) -> [1,3,2] -> pop() -> [2,3]
    pq.push(5) -> [2,3,5] -> pop() -> [3,5]
    pq.push(6) -> [3,5,6] -> pop() -> [5,6]
    pq.push(4) -> [4,6,5] -> pop() -> [5,6]
    return pq.top() -> 5 
    */   

    int n = nums.size();
    int result = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<n;i++){
        int num = nums[i];
        pq.push(num);

        if(pq.size() > k){
            pq.pop();
        }
    }
    result = pq.top();
    return result;
}

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    // Brute Solution
    cout << brute_findKthLargest(nums, k) << endl;

    // Optimal Solution
    cout << optimal_findKthLargest(nums, k) << endl;
    
}

