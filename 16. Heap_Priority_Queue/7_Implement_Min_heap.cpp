#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Implement Min Heap - Most important - Microsoft 2025

You need to implement the Min Heap with the following given methods.

    initializeHeap -> Initialize the heap
    1. insert (x) -> insert value x to the  heap
    2. getMin -> Output the minimum value from min heap
    3. exctractMin -> Remove the minimum element from the heap
    4. heapSize -> return the current size of the heap
    5. isEmpty -> returns if heap is empty or not
    6. deleteElement( i ): Delete the element present at the 'i' th index.
    7. changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)


*/


class MinHeap {
private: 

    // Heapify Up (Iterative) -> maintain min heap property from bottom to top
    void heapifyUp(int i) {
        int parent = (i - 1) / 2; 
        while (i > 0 && heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    // Heapify Down (Iterative) -> maintain min heap property from top to bottom
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2*i+1;
            int right = 2*i+2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else break;
        }
    }

public:
    vector<int> heap;  // Array to store heap elements

    // 1. Insert a new value
    void insert(int val) {
        // Time complexity: O(log n)
        // Space complexity: O(1)

        // Insert at the end
        heap.push_back(val);

        // Fix position (heapify-up)
        heapifyUp(heap.size() - 1);
    }


    // 3. Extract Min (remove root element)
    int deleteion() {
        // Time complexity: O(log n)
        // Space complexity: O(1)

        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
        return root;
    }

    // 4. Get Min (peek root element without removing)
    int getMin() {
        // Time complexity: O(1)
        // Space complexity: O(1)

        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap[0];
    }

    // 5. Delete key at given index
    void deleteElementAtIndex(int index) {
        // Time complexity: O(log n)
        // Space complexity: O(1)

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

        // Replace index-th node with last node
        heap[index] = heap[n - 1];

        // Remove last node
        heap.pop_back();

        if (index == n - 1) return; // last element deleted, done

        // Move the index-th node to its correct position
        int parent = (index - 1) / 2;
        if (index < heap.size() && heap[index] < heap[parent]) {
            heapifyUp(index);   // go up if smaller than parent
        } else {
            heapifyDown(index); // otherwise go down
        }
    }


    // 6. Change key at given index to newVal
    void changeKey(int index, int newVal) {
        // Time complexity: O(log n)
        // Space complexity: O(1)


        if (index < 0 || index >= heap.size()) return;

        int oldVal = heap[index];
        heap[index] = newVal;

        if (newVal < oldVal) {
            heapifyUp(index); // move up if smaller
        } else {
            heapifyDown(index); // move down if larger
        }
    }

    // 7. Print heap
    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << "\n";
    }
};

int main() {
    MinHeap h;

    // Insert elements
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(2);

    cout << "Heap elements: ";
    h.printHeap();

    cout << "Extract Min: " << h.deleteion() << "\n";
    cout << "Heap after extractMin: ";
    h.printHeap();

    cout << "Current Min: " << h.getMin() << "\n";

    h.changeKey(2, 1);
    cout << "Heap after changeKey: ";
    h.printHeap();

    h.deleteElementAtIndex(1);
    cout << "Heap after deleteKey: ";
    h.printHeap();

    return 0;
}
