#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Input: nums = [1], k = 1
Output: [1]

NOTE - By default, C++'s priority_queue is a max heap, meaning it always removes the largest element first ie from front().

Follow up ques -> if it is minimum , ans = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
*/

vector<int> brute_maxSlidingWindow(vector<int>& arr, int k) {
    // Time complexity - O(n*k)
    // Space complexity - O(1)
    int n=arr.size();
    vector<int>result;
    for(int i=0;i<n-k+1;i++){
        int maxi=-1;
        for(int j=i;j<i+k;j++){
            maxi=max(maxi, arr[j]);
        }
        result.push_back(maxi);
    }
    return result;
}

vector<int> optimal_maxSlidingWindow(vector<int>& arr, int k){
    // Time Complexity: O(n log n), Where n is the size of the array.
    //  Auxiliary Space: O(n)

    int n=arr.size();
    vector<int> result;
    priority_queue<pair<int,int>> heap;
    
    // Initialize the max heap with the first k elements
    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });
    
    // The maximum element in the first window
    result.push_back(heap.top().first);

    
    // Process the remaining elements
    for (int i = k; i < n; i++) {
    
        // Add the current element to the heap
        heap.push({ arr[i], i });
    
        // Remove elements that are outside the current window
        while (heap.top().second <= i - k)
            heap.pop();
    
        // The maximum element in the current window
        result.push_back(heap.top().first);
    }
    return result;
}

int main(){
    vector<int>arr={1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k=3;

    // brute 
    // vector<int>result=brute_maxSlidingWindow(arr,k);

    // optimal 
    vector<int>result=optimal_maxSlidingWindow(arr,k);

    for(auto it: result){
        cout<<it<<" ";
    }
}