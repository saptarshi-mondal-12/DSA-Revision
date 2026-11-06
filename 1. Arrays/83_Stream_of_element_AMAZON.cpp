#include <iostream>
#include<bits/stdc++.h>
using namespace std;


/*
Problem: Search for an Element in a Data Stream
You are given a data stream in which integer elements arrive one at a time. New elements can be added to the stream at any point.

You need to design a data structure that supports the following two operations:

add(x): Adds an integer x to the data stream.
exists(x): Checks whether the integer x has appeared in the stream so far. Returns true if it exists, otherwise returns false.
Queries can be made at any time, even while new elements are continuously arriving.
*/


// Uisng vector ----------------------------------------
// Follow question - Solve it without using unordered_set or unordered_map
// class streamSearch{
// private: 
//     vector<int>s;
// public:
//     void add(int val){
//         // Time complexity: O(1)
//         s.push_back(val);
//     }
//     bool exists(int x){
//         // Time complexity: O(n)
//         for(auto it: s){
//             if(it == x){
//                 return true;
//             }
//         }
//         return false;
//     }
// };





// Using unordered_set -------------------------------
// Follow up Q. How unordered set works internally. 
// Ans: Already cover in array folder. 
// class streamSearch{
//     private: 
//         // space complexity: O(n)
//         unordered_set<int>st;
//     public:
//     void add(int val){
//         // Time complexity: O(1)
//        st.insert(val);
//     }
//     bool exists(int x){
//         // Time complexity: O(1)
//         if(st.find(x) != st.end()){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };






/* Using set data structure Method 
Follow up - Optimize further. 
In C++, set data structure uses a self-balancing Red-Black Tree.
It maintains elements in sorted order and guarantees O(log N) insertion and search. 

A set is a data structure that:

Stores unique elements (no duplicates).
Keeps elements in sorted order.
Supports insertion, deletion and searching efficiently.

A C++ set generally uses a Red-Black Tree.
A Red-Black Tree is a type of self-balancing Binary Search Tree (BST).
*/
class streamSearch {
private:
    set<int> s;
public:
    // Add an element to the stream
    void add(int val) {
        // Time complexity: O(log n)
        s.insert(val);
    }

    // Check whether an element exists
    bool exists(int x) {
        // Time complexity: O(log n)
        return s.find(x) != s.end();
    }
};


int main(){
    streamSearch stream;
    // Stream elements arrive over time
    stream.add(10);
    stream.add(20);
    stream.add(30);
    stream.add(40);

    // Queries can be made at any time
    cout << stream.exists(20) << endl;  // Expected: 1
    cout << stream.exists(50) << endl;  // Expected: 0

    // More elements arrive
    stream.add(50);
    stream.add(60);

    // New queries
    cout << stream.exists(50) << endl;  // Expected: 1
    cout << stream.exists(60) << endl;  // Expected: 1
    cout << stream.exists(70) << endl;  // Expected: 0

    return 0;
    
}

