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




------------------------------------------Some Imortant Points------------------------------------------

Q1. What is a Cache?
A cache is a high-speed storage layer that stores frequently or recently accessed data so that future requests can be served faster.

Example: Suppose an application frequently fetches user information from a database.

Without caching:
    User requests profile.
    Application queries the database.
    Database returns the result.

With caching:
    User requests profile.
    Application checks the cache.
    If data exists, return it immediately.
    Otherwise, fetch from the database and store it in the cache.

Q2. Why do we need caching?
Reduce database load.
Improve application response time.
Reduce network calls.
Improve throughput.
Reduce computational cost.

Q3. What are Cache Hit and Cache Miss?
Cache Hit: Requested data is already present in the cache.
Cache Miss: Requested data is not present, so we fetch it from the original data source.

Hit Ratio = Total Requests/Cache Hits
​
A higher hit ratio generally means better cache effectiveness.


Q4. What is Cache Eviction?
When a cache reaches its maximum capacity and a new element needs to be inserted, we must decide which existing element to remove.
This process is called cache eviction.
Popular eviction policies:
LRU – Least Recently Used.
LFU – Least Frequently Used.
FIFO – First In First Out.
Random Replacement.
MRU – Most Recently Used.


Q5. What is LRU Cache?
LRU stands for Least Recently Used.
It removes the element that has not been accessed for the longest period of time when the cache reaches its capacity.


Q6. Which data structures are used in LRU Cache and why?
We use:

1. HashMap Stores key → node mapping.
Provides O(1) average lookup.

2. Doubly Linked List
Maintains the usage order.
Allows O(1) deletion and insertion when we already have a node reference.

Q. Why not use a normal singly linked list?
Because deleting a node in a singly linked list requires access to its previous node. A doubly linked list allows us to remove a given node directly in O(1).


Q7. What is the time complexity of LRU Cache?
get(key)
O(1) average

put(key, value)
O(1) average

Delete node
O(1)

Insert at head
O(1)

Search key
O(1) average

Space
O(capacity)


Q8. Why do we move a node to the head after get()?
Because accessing an element makes it the most recently used element.

Our convention:
Head = Most Recently Used (MRU).
Tail = Least Recently Used (LRU).
Therefore, every successful get() moves the node to the head.


Q9. What happens when we update an existing key?
Suppose:

put(1, 100)
Key 1 already exists.
We should:
Find its node using the HashMap.
Update its value.
Move it to the head.
We should NOT create a duplicate node.


Q10. What happens if capacity is zero?
No element can be stored.
put() should effectively do nothing, and get() should return -1.





3. LFU Cache (Least Frequently Used)

Q12. What is LFU Cache?
LFU stands for Least Frequently Used.
It removes the element with the lowest access frequency when the cache reaches its capacity.


Q13. How is LFU different from LRU?
The fundamental difference:
LRU considers when an element was accessed.
LFU considers how many times an element was accessed.

If eviction happens:
LRU may remove A because it was accessed long ago.
LFU removes B because it has the lowest frequency.


Q14. Which data structures are used in LFU Cache?
This is one of the most important interview questions.

For O(1) average get() and put(), we use three data structures:

1. HashMap: key → node

Finds a key in O(1) average time.

2. HashMap: frequency → doubly linked list

Maintains all nodes having the same frequency.

Within each frequency, we maintain recency order.

3. Minimum Frequency variable

Tracks the minimum frequency currently present in the cache.

Helps identify which frequency list to evict from.

I have completed practicing the LRU Cache code. Now prepare me for lru & lfu cache for sde interview. theoritical and expected interview question

Since you've already completed coding the LRU Cache, let's prepare you for LRU and LFU Cache from an SDE interview perspective.

The goal is not just to memorize implementations. You should be able to:

Explain the concepts clearly in 1–2 minutes.

Explain why particular data structures are used.

Compare LRU vs LFU.

Analyze time and space complexity.

Handle implementation and design follow-up questions.

Answer tricky edge cases and interviewer cross-questions.

I'll structure this like an interview preparation sheet, starting with fundamentals and moving toward advanced questions.


Q22. Which is better: LRU or LFU?
There is no universally better policy.

LRU is better when:

Recently accessed data is likely to be accessed again.

Workloads have changing access patterns.

You want a relatively simple implementation.

LFU is better when:

Some data is consistently accessed much more frequently.

Frequently accessed data should remain cached even if it hasn't been accessed recently.

Q23. What is a disadvantage of LFU?
LFU can suffer from the cache pollution problem.

Example:

Suppose an element was accessed 1,000 times in the past.

Now it is no longer needed.

Its high frequency may prevent it from being evicted even though it is no longer useful.

This is sometimes called the stale frequency problem.

One solution is frequency aging, where frequencies gradually decrease over time.

Q24. Can LFU be implemented using only a HashMap?
A simple LFU implementation can use a HashMap and additional frequency tracking, but achieving O(1) average operations and efficiently handling eviction and recency tie-breaking requires more sophisticated structures.

5. Expected SDE Interview Questions
These are questions I would prioritize after you have understood both implementations.

Must prepare
Basic-level questions
What is caching?
What is cache eviction?
What is LRU?
What is LFU?
Why do we use HashMap in LRU?
Why do we use Doubly Linked List?

Why are dummy head and tail nodes useful?
What is the difference between LRU and LFU?
What is a cache hit and cache miss?
What happens when cache capacity is zero?

Intermediate-level questions
Why is LRU O(1)?
Why can't we efficiently implement LRU using only a HashMap?
What happens when an existing key is updated?
How does LFU maintain frequency?
Why does LFU need minFreq?
How do we handle equal frequencies in LFU?
Why does LFU need multiple doubly linked lists?
What happens when the minimum-frequency list becomes empty?
What is the difference between FIFO and LRU?
Why can LFU perform poorly for changing workloads?

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