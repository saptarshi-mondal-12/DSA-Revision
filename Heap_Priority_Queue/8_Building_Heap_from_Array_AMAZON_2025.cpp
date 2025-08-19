#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Building Heap from Array 

Given an array of n elements. The task is to build a Max Heap from the given array.

Examples: 

Input: arr[] = {4, 10, 3, 5, 1}
Output: Corresponding Max-Heap:

       10
     /   \
   5     3
  /  \
4    1

Input: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
Output: Corresponding Max-Heap:

                 17
              /      \
          15         13
         /    \      /  \
       9      6    5   10
     / \    /  \
   4   8  3    1

   
Note: 
Root is at index 0 in array.
Left child of i-th node is at (2*i + 1)th index.
Right child of i-th node is at (2*i + 2)th index.
Parent of i-th node is at (i-1)/2 index. 



--------------------------------------------------------------------------------------------
NOTE: 

The structure of the code for build max heap and build min heap is exactly the same.
The only difference lies in the comparison condition inside the heapify function:

🔹 Max Heapify

Parent should be greater than children.

if (left < n && arr[left] > arr[largest]) {
    largest = left;
}
if (right < n && arr[right] > arr[largest]) {
    largest = right;
}

🔹 Min Heapify

Parent should be smaller than children.

if (left < n && arr[left] < arr[smallest]) {
    smallest = left;
}
if (right < n && arr[right] < arr[smallest]) {
    smallest = right;
}

*/

// Max-heap Implementation
class buildMaxHeap{
    public: 

    vector<int>heap;

    void heapifyDown(int i) {
        // TC: O(log n)
        // SC: O(1)

        int n = heap.size();
        while (true) {
            int left = 2*i+1;
            int right = 2*i+2;
            int largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    // Function to build a Max-Heap from the given array
    void buildHeap(vector<int>arr){
        // Time Complexity Analysis: Heapify a single node takes O(log n) time complexity where n is the total number of Nodes. Therefore, building the entire Heap will take n heapify operations and the total time complexity will be O(n*logn).

        
        int n=arr.size();

        heap = arr; 

        // Index of last non-leaf node
        int startIdx = (n / 2) - 1;

        // Perform reverse level order traversal from last non-leaf node and heapify each node
        for (int i = startIdx; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void printHeap(){
        cout << "Array representation of Heap is:\n";
        for (int i = 0; i < heap.size(); ++i)
            cout << heap[i] << " ";
        cout << "\n";
    }
};




int main(){
    buildMaxHeap h;
    
    // Binary Tree Representation
    // of input array
    //             1
    //           /    \
    //         3        5
    //       /  \     /  \
    //     4      6  13  10
    //    / \    / \
    //   9   8  15 17
    vector<int>arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};


    // Function call
    h.buildHeap(arr);
    h.printHeap();
  
    // Final Heap:
    //              17
    //            /    \
    //          15      13
    //         /  \     / \
    //        9     6  5   10
    //       / \   / \
    //      4   8 3   1

    return 0;
}