#include<bits/stdc++.h>
using namespace std;

/* Q. LRU Cache Implementation - AMAZON 2025

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
    1. LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

    2. int get(int key) Return the value of the key if the key exists, otherwise return -1.

    3. void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.


Intuition:
----------

[most-Recent, *, *, *, *, least-Recent]

To implement an LRU Cache with O(1) time complexity for both get and put operations, we can use a combination of a doubly linked list and a hash map (unordered_map in C++).

The intuition behind an LRU (Least Recently Used) Cache is that we want to store only a fixed number of items in memory and quickly evict the item that hasn’t been used for the longest time. This is useful when memory is limited and we want to keep the most relevant data available for fast retrieval. The key idea is to maintain quick lookups to check if a value exists in the cache, and also maintain the usage order so we can remove the least recently used item efficiently when the cache is full.

To implement it efficiently, we combine two data structures: a HashMap for O(1) lookup of keys, and a Doubly Linked List to maintain the order of usage. The most recently used items are kept at one end (head), and the least recently used items at the other end (tail). When we access or insert a key, we move it to the head whereas when the cache is full, we remove the tail node. This combination ensures both O(1) access and O(1) insertion/deletion for LRU operations.

    1. Use a HashMap to store key-value pairs for direct access to elements in the cache.
    2. Maintain a Doubly Linked List to track the usage order, with the most recently used node at the head and the least recently used at the tail.
    3. On a get(key) operation, if the key exists, move the corresponding node to the head and return its value, otherwise, return a cache miss value.
    4. On a put(key, value) operation, if the key exists, update the value and move it to the head. If it does not exist, create a new node, insert it at the head, and store it in the HashMap.
    5. If the cache exceeds capacity after an insertion, remove the node at the tail and delete its entry from the HashMap.

    
Time Complexity: get() function: O(1), accessing a value in the HashMap is O(1) on average.
put() function: O(1), checking and removing from the map as well as inserting into the doubly linked list is O(1).

Space Complexity: O(capacity) , for storing up to capacity nodes in the doubly linked list and map.

*/

// Double Linked List Class Node
class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        // Constructor to initialize node
        Node(int key, int val){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

// LRU Cache Class
class LRUCache{
    public:

    // Head and tail dummy nodes
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Capacity of cache
    int capacity;

    // Hash map to store key-node mapping
    unordered_map<int, Node*>m;

    // Constructor to initialize LRU Cache
    LRUCache(int capacity){
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to add node right after head
    void addNode(Node* node){
        Node* nextNode = head->next; // get the node next to head
        head->next = node; // link head to new node
        node->prev = head; // link new node to head
        node->next = nextNode; // link new node to next node
        nextNode->prev = node; // link next node to new node
    }

    // Function to delete a node from the linked list
    void deleteNode(Node* deleteNode){
        Node* deletePrev = deleteNode->prev; // get previous node
        Node* deleteNext = deleteNode->next; // get next node
        deletePrev->next = deleteNext; // link previous node to next node
        deleteNext->prev = deletePrev; // link next node to previous node
    }

    // Function to get value of key
    int get(int key){
        // If key not found, return -1
        if(m.find(key) == m.end()){
            return -1;
        }

        // Key found, get the node
        Node* resNode = m[key];
        int res = resNode->val;

        // Remove old mapping
        m.erase(key);

        // Remove the node from its current position
        deleteNode(resNode);

        // Add the node right after head (most recently used)
        addNode(resNode);

        // update map
        m[key] = head->next;

        return res;
    }

    // Function to put key-value pair in cache
    void put(int key, int value){
        // If key already exists, update the value
        if(m.find(key) != m.end()){
            Node* existingNode = m[key];
            // Remove old mapping
            m.erase(key);
            // Delete the node from its current position
            deleteNode(existingNode);
        }

        // If cache is at capacity, remove the least recently used item
        if(m.size() == capacity){
            Node* lruNode = tail->prev; // get the least recently used node
            // Remove from map
            m.erase(lruNode->key);
            // Delete the node from linked list
            deleteNode(lruNode);
        }

        // Create a new node
        Node* newNode = new Node(key, value);
        // Add the new node right after head (most recently used)
        addNode(newNode);
        // Update map
        m[key] = head->next;
    }

};

int main() {
    // Create cache with capacity 2
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl; 

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl; 

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl; 

    // Key 3 should be present
    cout << cache.get(3) << endl; 

    // Key 4 should be present
    cout << cache.get(4) << endl; 

    return 0;
}