#include<bits/stdc++.h>
using namespace std;

/* Q. LFU Cache Implementation - AMAZON 2025

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

    LFUCache(int capacity) Initializes the object with the capacity of the data structure.

    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.

    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]



Intuition:
----------


Time Complexity: O(N), where N is the number of queries on the LFU cache. Each get and put method takes an average of constant time, making the overall complexity O(N).

Space Complexity: O(cap), where cap is the capacity of the LFU cache. The cache can store a maximum of cap data items, taking O(cap) space.


*/

// Double Linked List Class Node
class Node{
    public:
        int key;
        int val;
        int count;
        Node* next;
        Node* prev;

        // Constructor to initialize node
        Node(int key, int val){
            this->key = key;
            this->val = val;
            count = 1;
            this->next = NULL;
            this->prev = NULL;
        }
};

// To implement the doubly linked list
class List{
    public: 

        int size;

        // Head and tail dummy nodes
        Node* head;
        Node* tail;

        // Constructor
        List(){
            head = new Node(0, 0); 
            tail = new Node(0,0); 
            head->next = tail;
            tail->prev = head; 
            size = 0;
        }

        // Function to add node in front 
        void addFront(Node *node) {
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++; 
        }
        
        // Function to remove node from the list
        void removeNode(Node* delnode) {
            Node* prevNode = delnode->prev;
            Node* nextNode = delnode->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            size--; 
        }
};

// LFU Cache Class
class LFUCache{
    private:

        // Hashmap to store the key-nodes pairs
        map<int, Node*>keyNode;

        // Hashmap to maintain the lists having different frequencies
        map<int, List*>freqListMap;

        // Max size of cache
        int maxSizeCache; 

        // To store the frequency of least frequently used data-item 
        int minFreq; 
   
        // To store current size of cache
        int curSize; 
    
    public:

        // Constructor
        LFUCache(int capacity){
            maxSizeCache = capacity;
            minFreq = 0; // Set minimum frequency
            curSize = 0; // Set current frequency
        }


        // Method to update frequency of data-items
        void updateFreqListMap(Node *node) {
            
            // Remove from Hashmap
            keyNode.erase(node->key); 
            
            // Update the frequency list hashmap
            freqListMap[node->count]->removeNode(node); 
            
            // If node was the last node having it's frequency
            if(node->count == minFreq && freqListMap[node->count]->size == 0) {
                // Update the minimum frequency
                minFreq++; 
            }
            
            // Creating a dummy list for next higher frequency
            List* nextHigherFreqList = new List();
            
            // If the next higher frequency list already exists
            if(freqListMap.find(node->count + 1) != freqListMap.end()) {
                    
                // Update pointer to already existing list
                nextHigherFreqList = freqListMap[node->count + 1];
            } 
            
            // Increment the count of data-item
            node->count += 1; 
            
            // Add the node in front of higher frequency list
            nextHigherFreqList->addFront(node); 
            
            // Update the 
            freqListMap[node->count] = nextHigherFreqList; 
            keyNode[node->key] = node;
        }
    
        // Method to get the value of key from LFU cache
        int get(int key) {
            
            // Return the value if key exists
            if(keyNode.find(key) != keyNode.end()) {
                Node* node = keyNode[key]; // Get the node
                int val = node->val; // Get the value
                updateFreqListMap(node); // Update the frequency
                
                // Return the value
                return val; 
            }
            
            // Return -1 if key is not found
            return -1; 
        }
        
        void put(int key, int value) {
            // If the size of Cache is 0, no data-items can be inserted 
            if (maxSizeCache == 0) {
                return;
            }
            
            // If key already exists
            if(keyNode.find(key) != keyNode.end()) {
                
                // Get the node
                Node* node = keyNode[key]; 
                
                // Update the value
                node->val = value; 
                
                // Update the frequency
                updateFreqListMap(node); 
            }
            
            // Else if the key does not exist
            else {
                
                // If cache limit is reached
                if(curSize == maxSizeCache) {
                    
                    // Remove the least frequently used data-item
                    List* list = freqListMap[minFreq]; 
                    keyNode.erase(list->tail->prev->key); 
                    
                    // Update the frequency map 
                    freqListMap[minFreq]->removeNode(list->tail->prev);
                    
                    // Decrement the current size of cache
                    curSize--; 
                }
                
                // Increment the current cache size
                curSize++; 
                
                // Adding new value to the cache
                minFreq = 1; // Set its frequency to 1
                
                // Create a dummy list
                List* listFreq = new List(); 
                
                // If the list already exist
                if(freqListMap.find(minFreq) != freqListMap.end()) {
                    
                    // Update the pointer to already present list
                    listFreq = freqListMap[minFreq]; 
                }
                
                // Create the node to store data-item
                Node* node = new Node(key, value); 
                
                // Add the node to dummy list
                listFreq->addFront(node);
                
                // Add the node to Hashmap
                keyNode[key] = node; 
                
                // Update the frequency list map 
                freqListMap[minFreq] = listFreq; 
            }
        }

};

int main() {
  // LFU Cache
  LFUCache cache(2);

  // Queries
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << " ";
  cache.put(3, 3);
  cout << cache.get(2) << " ";
  cout << cache.get(3) << " ";
  cache.put(4, 4);
  cout << cache.get(1) << " ";
  cout << cache.get(3) << " ";
  cout << cache.get(4) << " ";

  return 0;
}