#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/* Q. Implement Max Heap - Most important - Microsoft 2025

A Max Heap is a complete binary tree where the value of each parent node is greater than or equal to the value of its children. Thus, the maximum element is always stored at the root.

     100
    /   \
  50     80
 /  \
30  40


You need to implement the Min Heap with the following given methods.

    initializeHeap -> Initialize the heap
    1. insert (x) -> insert value x to the heap
    2. getMax -> Output the maximum value from max heap
    3. exctractMaz -> Remove the maximum element from the heap
    4. heapSize -> return the current size of the heap
    5. isEmpty -> returns if heap is empty or not
    6. deleteElement( i ): Delete the element present at the 'i' th index.
    7. changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)



------------------------------------------------------------------------------------------------------------------------------------------

Q. What is Heap?
Ans: A Heap is a complete binary tree that satisfies the heap property:
    In a Max Heap, every parent node has a value greater than or equal to its children.
    In a Min Heap, every parent node has a value less than or equal to its children.

filling - left to right (complete binary tree)

Max Heap : Maximum element at top/front/root node

    |
    |
    | decreasing order
    |
    v

      55
    /    \
   54     53
  /  \
 50  52 


NOTE :  Follow Up Ques : Build Max heap from given array

*/


class MaxHeap{
private:
    vector<int>heap;

    // Heapify-Up - Move element up until heap property is restored
    void heapifyUp(int i) {
        // TC: O(log n)
        // SC: O(1)

        int parent = (i - 1) / 2; 
        while (i > 0 && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
        }
    } 

    // Heapify-down - Move element down until heap property is restored
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

public:

    // 1. Inserts a new element into the heap.
    void insert(int val){
        // Time complexity : O(log n) because we are doing index/2 every time

        // Insert at end
        heap.push_back(val);

        // Take it to its correct position
        int index = heap.size() - 1;
        heapifyUp(index);
    }


    // 2. Deletion - Removes and returns the maximum element (root). (Max heap - Always removing the root node)
    int deletion(){
        // Time complexity : O(log n) 

        if (heap.size() == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        if(heap.size() == 1){
            int maxVal = heap[0];
            heap.pop_back();
            return maxVal;
        }

        // Swap root node with last node
        int n = heap.size();
        int maxVal = heap[0];
        heap[0] = heap[n-1];


        // Remove last node - (now root is at last index, so simple remove from heap)
        heap.pop_back();

        // Move new root node to its correct position
        heapifyDown(0);

        // return ans
        return maxVal;
    }

    // 3. GetMax - Returns the maximum element without removing it. i.e root node, value at 0th index
    int getMax(){
        // Time complexity: O(1)

        if (heap.size() != 0){
            int front = heap[0];
            return front;
        }
        cout << "Heap is empty\n";
        return -1;
    }


    // 4. heapSize - Returns the current number of elements in the heap.
    int heapSize(){
        int size = heap.size();
        return size;
    }

    // 5. deleteElement(i): Delete the element present at the 'i' th index.
    void deleteElementAtIndex(int index){
        int n = heap.size();
        
        if (index < 0 || index >= n) {
            cout << "Invalid index\n";
            return;
        }
        if (n == 0) {
            cout << "Heap is empty\n";
            return;
        }
        if (n == 1) {
            heap.pop_back();
            return;
        }


        // Swap index th node with last node
        heap[index] = heap[n-1];

        // Remove last node 
        heap.pop_back();

        if (index == n - 1) return; // last element deleted, done

        // Move the index th node to its correct position - (Decide whether to heapify-up or down)
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            heapifyUp(index);
        } else {
            heapifyDown(index);
        }
    }


    // 6. ChangeKey (ind, val) -> update the value at given index to val
    void changeKey(int index, int newVal){
        // TC: O(log n)
        // SC: O(1)
        int n = heap.size();
        if (index < 0 || index >= n) {
            cout << "Invalid index\n";
            return;
        }

        int oldVal = heap[index];
        heap[index] = newVal;

        if (newVal > oldVal) {
            // Heapify-up
            heapifyUp(index);
        } 
        else if (newVal < oldVal) {
            // Heapify-down
            heapifyDown(index);
        }
    }

    // Print Heap
    void print(){
        for(int i=0;i<heap.size();i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
};


int main() {
    MaxHeap h;

    // Insert elements
    h.insert(50);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(10);
    h.insert(8);
    h.insert(16);

    cout << "Heap after insertions: ";
    h.print();

    cout << "Max element: " << h.getMax() << endl;

    cout << "Extracted Max: " << h.deletion() << endl;

    cout << "Heap after extractMax: ";
    h.print();

    h.deleteElementAtIndex(2);
    cout << "Heap after deleting index 2: ";
    h.print();

    h.changeKey(1, 60);
    cout << "Heap after changeKey(1, 60): ";
    h.print();

    cout << "Heap size: " << h.heapSize() << endl;

    return 0;
}




/* Follow up questions : 

1️⃣ How do you delete an arbitrary index from the heap? Given an index i in the heap array, remove that element while maintaining the min-heap property.
Ans: Swap it with the last element.
Remove the last element (pop_back).
If the new value at index i is smaller than its parent → call heapifyUp(i).
Else → call heapifyDown(i).

4️⃣ How do you merge two min-heaps?
Q: Merge two min-heaps into one.
Ans: Concatenate their arrays. Call buildHeap() on the result (O(n) time).
Avoid inserting one-by-one (O(n log n)) unless heap sizes are small.


5️⃣ How do you convert a min-heap to a max-heap?
Ans: Traverse all elements and multiply by -1 (or reverse comparison logic).
Call buildHeap() again.


6️⃣ How do you find the k smallest elements in an array?
Ans: Approach 1 (Min Heap):
Build a min-heap with all elements (O(n)).
Extract min k times (O(k log n)).

Approach 2 (Max Heap of size k):
Maintain a max heap of size k while iterating.
Replace root if new element is smaller.

7️⃣ What’s the difference between priority_queue in C++ and your heap?
Ans: priority_queue in C++ is max-heap by default (unless you pass a custom comparator).
My heap is min-heap by design.
priority_queue is built on top of a vector + make_heap, push_heap, pop_heap utilities.


1️⃣Can you support both Min and Max Heap in the same class?
Ans: Yes — store a bool isMinHeap flag and flip comparison logic in heapify.


5️⃣Can heaps be used for sorting?
Ans: Yes — Heap Sort.
Build heap (O(n)).
Repeatedly extract min (O(n log n)).
Result: sorted array.

*/