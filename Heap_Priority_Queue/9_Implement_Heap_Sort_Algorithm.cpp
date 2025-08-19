#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Heap Sort Algorithm - (Ascending Order)

        70
       /  \
      60   55
     /  \
    45  50

    [70,60,55,45,50]



Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure. It can be seen as an optimization over selection sort where we first find the max (or min) element and swap it with the last (or first). We repeat the same process for the remaining elements. In Heap Sort, we use Binary Heap so that we can quickly find and move the max element in O(Log n) instead of O(n) and hence achieve the O(n Log n) time complexity.



Algorithm: 

First convert the array into a max heap using heapify, Please note that this happens in-place. The array elements are re-arranged to follow heap properties. Then one by one delete the root node of the Max-heap and replace it with the last node and heapify. Repeat this process while size of heap is greater than 1.

    1. Swap the root element of the heap (largest) with the last element.
    2. Reduce the heap size by 1 and heapify the new root down.
This repeats until the heap size becomes 1, and the array is sorted.
Finally we get sorted array.


Iteraion 1: 
step 1: last index = 4, ==> swap arr[0] with arr[lastIndex]
    Before swap: 
        70
       /  \
      60   55
     /  \
    45  50


    After swap:
        50
       /  \
      60   55
     /  \
    45  70 

step 2: 
    After heapfy - (moving root (50) to its correct position)
        60
       /  \
      50   55
     / 
    45  

      unsorted       sorted
    [60,50,55,45,  |   70   ]



Iteraion 2: 
step 1: last index = 3, ==> swap arr[0] with arr[lastIndex]
    Before swap :
        60
       /  \
      50   55
     / 
    45

    After swap :
        45
       /  \
      50   55
     / 
    60

step 2: 
    After heapfy - (moving root 45 to its correct position)
        55
       /  \
      50   45
    

      unsorted     sorted
    [55,50,45,  |  60,70  ]



Iteraion 3: 
step 1: last index = 2, ==> swap arr[0] with arr[lastIndex]
    Before swap :
        55
       /  \
      50   45

    After swap :
        45
       /  \
      50   55
     

step 2: 
    After heapfy - (moving root 45 to its correct position)
        50
       /  
      45   
    

     unsorted    sorted
    [50,45,   | 55,60,70 ]


Iteraion 4: 
step 1: last index = 1, ==> swap arr[0] with arr[lastIndex]
    Before swap :
        50
       /  
      45   
     

    After swap :
        45
       /  
      50   

step 2: 
    After heapfy - (moving root 45 to its correct position)
        45
       
     

      unsorted      sorted
    [45,        | 50, 55,60,70 ]



Iteraion 5: 
step 1: last index = 0, ==> swap arr[0] with arr[lastIndex]
    Before swap :
        45

    After swap :
        45
       

step 2: 
    After heapfy - (moving root to its correct position)
        45
       /  \
      50   55
     /  \
    60  70

    [45,50,55,60,70]


Final answer = [45,50,55,60,70]



Important points about Heap Sort
    1. Heap sort is an in-place algorithm.
    2. Its typical implementation is not stable but can be made stable (See this)
    3. Typically 2-3 times slower than well-implemented QuickSort. The reason for slowness is a lack of locality of reference.

Advantages of Heap Sort
    1. Efficient Time Complexity: Heap Sort has a time complexity of O(n log n) in all cases. This makes it efficient for sorting large datasets. The log n factor comes from the height of the binary heap, and it ensures that the algorithm maintains good performance even with a large number of elements.

    2. Memory Usage: Memory usage can be minimal (by writing an iterative heapify() instead of a recursive one). So apart from what is necessary to hold the initial list of items to be sorted, it needs no additional memory space to work
    
    3. Simplicity: It is simpler to understand than other equally efficient sorting algorithms because it does not use advanced computer science concepts such as recursion.

Disadvantages of Heap Sort
    1. Costly: Heap sort is costly as the constants are higher compared to merge sort even if the time complexity is O(n Log n) for both.
    2. Unstable: Heap sort is unstable. It might rearrange the relative order.
    3. Inefficient: Heap Sort is not very efficient because of the high constants in the time complexity.

*/


void heapifyDown(vector<int>& arr, int i, int n) {
    // TC: O(log n)
    // SC: O(1)

    while (true) {
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
        } else {
            break;
        }
    }
}


void heapSort(vector<int>& arr){
    // Time Complexity: O(n log n)
    // Space Complexity: O(1)

    int n = arr.size();

    // ---------------- Step 1: Build a Max-Heap ----------------

    // The last non-leaf node is at index (n/2 - 1).
    // Starting from this node and moving upwards ensures that every subtree becomes a valid heap, resulting in a complete max-heap.
    
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapifyDown(arr, i, n); // n because full check to put it in correct position
    }



    // ---------------- Step 2: Extract elements one by one ----------------

    // Repeatedly swap the root (largest element) with the last element of the heap,
    // then reduce the heap size by 1 and heapify again to restore heap property.
    for (int i = n - 1; i > 0; i--) {

        // move current max (root) to its correct sorted position i.e i th index
        swap(arr[0], arr[i]);

        // Take new root note to its correct position - heapfy-down
        heapifyDown(arr, 0, i);  // heap size reduces to 'i', so only [0..i-1] is heap.
    }
}


void printArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };

    // Function call
    heapSort(arr);

    cout << "Sorted array is : \n";
    printArray(arr);
}