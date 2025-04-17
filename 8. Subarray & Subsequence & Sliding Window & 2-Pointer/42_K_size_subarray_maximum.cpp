#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
K Sized Subarray Maximum
Given an array arr[] of integers and an integer k, your task is to find the maximum value for each contiguous subarray of size k. The output should be an array of maximum values corresponding to each contiguous subarray.

Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
Output: [3, 3, 4, 5, 5, 5, 6] 
Explanation: 
1st contiguous subarray = [1 2 3] max = 3
2nd contiguous subarray = [2 3 1] max = 3
3rd contiguous subarray = [3 1 4] max = 4
4th contiguous subarray = [1 4 5] max = 5
5th contiguous subarray = [4 5 2] max = 5
6th contiguous subarray = [5 2 3] max = 5
7th contiguous subarray = [2 3 6] max = 6

NOTE - By default, C++'s priority_queue is a max heap, meaning it always removes the largest element first ie from front().

Follow up ques -> if it is minimum , ans = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
*/

vector<int> brute_maxOfSubarrays(vector<int>& arr, int k) {
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

vector<int> optimal_maxOfSubarrays(vector<int>& arr, int k){
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
    // vector<int>result=brute_maxOfSubarrays(arr,k);

    // optimal 
    vector<int>result=optimal_maxOfSubarrays(arr,k);

    for(auto it: result){
        cout<<it<<" ";
    }
}