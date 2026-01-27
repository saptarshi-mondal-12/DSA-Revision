#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/* Kth Largest in a Stream - Amazon 2025

Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element) after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion.  return a list of size n after all insertions.

Example 1:

Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:[-1 -1 -1 1 2 3]
Explanation:
For 1, the 4th largest element doesn't exist so answer will be -1.
For 2, the 4th largest element doesn't exist so answer will be -1.
For 3, the 4th largest element doesn't exist so answer will be -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.



✅ Intuition-------------------------------------------------------

We are given a stream (array) of integers and a value k.
At each point in the stream, we want to know the kth largest element so far.

To do this efficiently:
    We maintain a min-heap of size k.
    This heap always contains the top k largest elements seen so far.
    The smallest among these k elements (i.e., the top of the min-heap) is the kth largest overall.

Q. Why min-heap?
Ans: Because we want quick access to the smallest of the top k elements.

When the heap grows beyond size k, we remove the smallest element (minHeap.pop()), keeping only the k largest.

*/



/* 
Brute Approach - Using Repeated Sorting 

add element into vector , sort vector , get kth largest element, add element into vector , sort vector , get kth largest element so on....................n times. 

Time complexity: O(n * O(n log n)) because for each time we push and sort. So we do for total n times.
*/ 

vector<int> kthLargest(int k, int arr[], int n) {
    /* 
    ✅ Total Time Complexity = O(n log k) n = number of elements, k = target kth largest.
        Insertion into min-heap: O(log k)
        Over n elements: O(n log k)

    💾 Space Complexity: O(k + n)
        We maintain a min-heap of size at most k: O(k)
        We store the result in a vector of size n: O(n)
    */
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        minHeap.push(num);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        if (minHeap.size() < k) {
            result.push_back(-1);
        } else {
            result.push_back(minHeap.top()); // kth largest
        }
    }

    return result;
}

int main(){
    int n=6;
    int arr[n]={1, 2, 3, 4, 5, 6};
    int k=4;

    vector<int>res=kthLargest(k,arr,n);
    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
}

