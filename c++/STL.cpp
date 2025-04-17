Time complexity - increasing time - O(log n) < O(n) < O(2n) < O(3n) < O(n log n) < O(n^2) < O(n^3)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int,int>p={1,3};
    cout<<p.first<<" "<<p.second<<endl; // 1 3

    pair<int,pair<int,int>> p1={1,{5,3}}; 
    cout<<p.first<<" "<<p1.second.first<<" "<<p1.second.second; // 1 5 3

    pair<int,int> arr[]={{1,2},{3,4},{5,6}};
    cout<<arr[1].second; // 4
}

void explainvector(){
    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);
    cout<<v[0]<<" "<<v[1]<<endl; // 1 2

    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.push_back({3,4});
    // vec={{1,2},{3,4}};
    cout<<vec[1].first<<" "<<vec[1].second<<endl; // 3 4

    // initialize vector of size 5 with 0
    vector<int> v1(5,0); //{0,0,0,0,0}

    // iterator
    for(auto it=v.begin(); it!=v.end(); it++)

    // copy one vector to another
    vector<int>v2(v1); //{0,0,0,0,0}

    

    // erase
    vector<int>vt={1,2,3,4,5,6,7,8};
    vt.erase(vt.begin()+2); // {1,2,4,5,6,7,8}

    // erase from range
    vt.erase(vt.begin()+3,vt.begin()+6); //{1,2,4,8}

    // insert element at specific position
    vector<int>v4(2,100);        //{100,100}
    v4.insert(v4.begin(),300);   //{300,100,100}
    v4.insert(v4.begin()+1,2,10); //{300,10,10,100,100} 
    
    // delete last element
    v.pop_back(); //{300,10,10,100}

    // erase entire vector
    v.clear();

    // Sort the vector in descending order - 9,8,7,6,5
    sort(v.begin(), v.end(), greater<>());

    // size
    v.size();
}

void explainStack(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5); 
    
    cout<<st.top()<<endl; //5

    st.pop(); // 4 3 2 1

    st.size(); //4

    st.empty(); // False
}

void explainQueue(){
    /*A queue is a linear list of elements in which deletions 
    can take place only at one end called the front, and insertions
    can take place only at the end called the rear. The queue is a 
    First In First Out type of data structure (FIFO),the terms FRONT 
    and REAR are used in describing a linear list only when it is implemented as a queue.*/
    
    queue<int>q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.push(3); // {1,2,3}
    q.push(4); // {1,2,3,4}
    
    cout<<q.back(); // 4

    cout<<q.front(); // 1

    q.pop(); //{2,3,4}

    cout<<q.front(); // 2

    cout<<q.size();

    cout<<q.empty()<<endl;
}

void explainPriorityQueue(){
    /* priority queues are a type of container adaptors, specifically designed such 
    that its first element is always the greatest of the elements it contains and the 
    rest elements are in decreasing order.*/ 

    priority_queue<int> pq;
    pq.push(5);    //{5}
    pq.push(2);   //{5,2}
    pq.push(8);  //{8,5,2}
    pq.push(10); //{10,8,5,2}

    cout<<pq.top(); //10

    pq.pop(); // {8,2,5}

    cout<<pq.top(); //8

    // store minimum element at top (mean heap)
    priority_queue<int, vector<int>, greater<int>>pq1;
    pq1.push(5);    //{5}
    pq1.push(2);   //{2,5}
    pq1.push(8);  //{2,5,8}
    pq1.push(10); //{2,5,8,10}

    cout<<pq1.top(); // 2


    
}

void explainSet(){
    // sorted order + unique element
    set<int>st;
    st.insert(1); //{1}
    st.insert(2); //{1,2}
    st.insert(2); //{1,2}
    st.insert(4); //{1,2,4}
    st.insert(3); //{1,2,3,4}
    st.insert(5); //{1,2,3,4,5}

    auto it=st.find(3);
    
    st.erase(5); //{1,2,3,4}
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << * it << " ";
    }
    cout<<endl;

    // check if element is present in list or not
    int count=st.count(1); // return True(1) or False(0) based on whether the element is present in the set or not.
    

    int n=2;
    if (st.find(2) != st.end())
    cout << n << " is present in set" << endl;

    // erase from range {1, 2, 3, 4, 5}
    set<int>s={1,2,3,4,5};
    auto it1=s.find(2);
    auto it2=s.find(4);
    s.erase(it1,it2); // {1,4,5}
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << * it << " ";
    }
    cout<<endl;

    // [[1,2],[1,4],[1,6]]
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({3,{1,2}});
    pq.push({5,{1,4}});
    pq.push({7,{1,6}});
    pq.push({9,{7,2}});
    pq.push({11,{7,4}});
    pq.push({13,{7,6}});
    pq.push({13,{11,2}});
    pq.push({15,{11,4}});
    pq.push({17,{11,6}});

    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second.first<<' '<<pq.top().second.second<<endl;
        pq.pop();
    }

}

void explainUnordered_set(){
    // stores unique element + no particular order (random order)
    unordered_set<int>st;
}

void explainMulti_Set(){

    // sorted but store multiple occurrence 
    // eg - {1,2,2,3,4,4,4,6}
    multiset<int>ms;
    ms.insert(1); //{1}
    ms.insert(2); //{1,2}
    ms.insert(2); //{1,2,2};

    ms.erase(2); // erase all occurrence of 2

    int cnt=ms.count(2);
    cout<<cnt<<endl; // 2

    ms.erase(ms.find(1)); // only a single one erased

    // erase first 2 occurrence of 1 
    // {1,1,1,1,2,3,3} 
    // result = {1,1,2,3,3}
    multiset<int> ms1={1,1,1,1,2,3,3};
    auto it1 = ms1.find(1); // Get the iterator to the first occurrence of 1
    auto it2 = ms1.find(1); // Get another iterator to the first occurrence of 1

    ms1.erase(it1, next(it2, 2)); // Erase the range defined by the iterators

    for (auto it = ms1.begin(); it != ms1.end(); it++) {
        cout << *it << " ";
    }
    cout<<endl; //{1,1,2,3,3}
}

void explainUnorderedMultiSet(){
    /*An unordered_multiset in STL is an associative container just like an unordered set the only difference is it can store duplicate elements in it.*/
    unordered_multiset<int> s;
    s.insert(1);
    s.insert(2);

    s.count(2); //returns 1

    if(s.find(2)!=s.end()) cout<<"true"<<endl;

    cout<<s.size()<<endl;





}

void explainMap(){
    //  map stores unique keys in sorted order 

    map<int,int>m{{1,2},{2,4},{4,8}};
    cout<<m[2]<<endl; //4

    // {key,value} {1:2, 2:5}
    map<int,int>mpp;

    // {1:{5,6}, 2:{7,2}, 3:{2,4}}
    map<int, pair<int,int>>mpp1;

    // {1:{1,2,3} , 2:{5,8,1}}
    map<int, vector<int>>mpp2;

    map<pair<int,int>, int>mpp3;

    // insert value 
    mpp[1]=2;
    mpp.insert({2,4});
    mpp[3]=6;
    mpp[4]=8;
    mpp.insert({5,10});

   // erase value
  //mpp.erase(key);

    // access specific key
    cout<<mpp[3]<<endl; // 6

    // printing map value
    for(auto i=0;i<mpp.size();i++){
        cout<<mpp[i]<<endl; 
    } // {0,2,4,6,8,10}

    // printing map value with key
    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    } // output
    /*
    1 2
    2 4
    3 6
    4 8
    5 10
    */

    // Checking if key 2 is present in the map

    auto it=mpp.find(2); // give address 
    // access the value
    if (it != mpp.end()) {
        cout << it->second << endl; // 4
    }
    // or
    if (mpp.count(2) > 0) cout << it->second << endl; //4
    
    // copy one map to another 
    map<int, int> mp(mpp.begin(), mpp.end());

}

void explainMultiMap(){
    // same as map 
    // store duplicate element +  sorted order 
    // {{1,2}, {1,3}, {2,0}};
}

void explainUnordered_Map(){
    // same as map
    // store unique keys + random order (not sorted)
}

void explainMore(){
    vector<int> v = {5, 6, 4, 9, 8, 3, 2, 7};

    // sorting in increasing order
    sort(v.begin(),v.end()); // 2 3 4 5 6 7 8 9 

    // sort in given range
    sort(v.begin()+2,v.begin()+6); // 5 6 3 4 8 9 2 7

    // sorting in descending order
    sort(v.begin(), v.end(), greater<int>()); // 9 8 7 6 5 4 3 2

    for(auto it:v) cout<<it<<" ";
    cout<<endl; 


    // __builtin_popcount is used count the number of bit positions in binary representation of an integer
    int num=8;
    int cnt= __builtin_popcount(num);
    cout<<cnt<<endl; // output 1000 -> 1 (count no of 1's in a binary )

    long long int numm=165786578687;
    int cntt= __builtin_popcountll(numm);
    // cout<<cnt<<endl;  24


    // finding maximum element from vector
    int mx=*max_element(v.begin(),v.end());
    cout<<mx<<endl;

    // convert integer into string 
    int n=12345;
    string s=to_string(n);
    
}


void hashing(){
    // 1. count frequency of element - number hashing

    int arr[8]={1,3,2,1,3,11,6,1}; 

    // maximum element 11 (create a hash of 12 element because 0 index + 11 as maxelement = 12  )

    // precompute + fetching
    int hash[12]={0}; // {0,0,0,0,0,0,0,0,0,0,0,0} 
    for(int i=0;i<8;i++){
        hash[arr[i]]+=1;
    }
    // O/P - {0 3 1 2 0 0 1 0 0 0 0 1 }

    // maximum size can be declare in array = arr[10^6] - inside main 
    // but we can declare 10^7 globally above int main arr[10^7 + 1]

    // 2. character hashing 

    // s="abcdabegc" 
    // a->2, c->2, z->0

    // 'a' -  97
    // 'b' - 98
    // 'z' - 122 

    // calculate for f -> 'f'-'a' = 5 (character hash index)

    string s="abcdabegc";
    int hashh[26]={0};
    for(int i=0;i<s.size();i++){
        hashh[s[i] - 'a']+=1;
    }
    // count frequency of 'a'
    cout<<hashh['a'-'a']<<endl; // 2
    // count frequency of 'c'
    cout<<hashh['c'-'a']<<endl; // 2
    // count frequency of 'z'
    cout<<hashh['z'-'a']<<endl; // 0

    // if all character upper +  lower use arr[256]
    // ch-'a' for lowercase
    // ch-'A' for uppercase

    // use map to store frequency
    int a[7]={1,2,3,1,3,2,12};
    map<int,int>mpp;
    for(int i=0;i<7;i++){
        mpp[a[i]]++;
    }
    for(auto it:mpp) cout<<it.first<<"->"<<it.second<<endl;
    /*
    1->2
    2->2
    3->2
    12->1
    */
    // time complexity - map -> storing + fetching = O(log n) in all cases 
    // time complexity - unordered_map -> storing + fetching = O(1) in (best and average case) and O(n) in worst case

}


Priority Queue : 
A priority queue is a container in C++ that provides constant-time to access the largest (or smallest) element while maintaining logarithmic time complexity for insertion and deletion. It is typically implemented using a heap.

1. MAX HEAP (Largest Element Has Highest Priority)

A Max Heap is a priority queue where the highest value element is at the top.
A max heap in C++'s priority_queue stores elements in descending order (largest value at the top). In C++'s priority_queue, heap.pop() always removes the top element, which is the largest element.

NOTE : Largest element at the top

🔹Syntax for Max Heap with Single Integers :
priority_queue<int> pq;

e.g 
pq.push(5);
pq.push(4);
pq.push(3);
pq.push(2);
pq.push(1);

Max Heap elements: 5 4 3 2 1


🔹Syntax for Max Heap with Pairs (pair<int, int>) :
priority_queue<pair<int, int>> pq;

e.g.
pq.push({1, 2});
pq.push({2, 3});
pq.push({5, 6});
pq.push({3, 4});

Max Heap of Pairs: {5,6} {3,4} {2,3} {1,2}

---- sort according to freq i.e second - increasing order , decreasing order
we can store {freq, val} 


------------------------------------------------------------------------------------------------------------------------------

2. MIN HEAP (Smallest Element Has Highest Priority) :

A Min Heap is a priority queue where the smallest value element is at the top. A min heap stores elements in ascending order, with the smallest element at the top. Now, minHeap.top() gives the smallest element and minHeap.pop() removes the smallest element.

NOTE : Smallest element at the top

🔹Syntax for Min Heap with Single Integers :
priority_queue<int, vector<int>, greater<int>> pq;

-------Breakdown:
priority_queue<int> → Stores integers.
vector<int> → Uses a vector as the underlying container.
greater<int> → Changes the default behavior from Max Heap to Min Heap.



e.g 
pq.push(5);
pq.push(4);
pq.push(3);
pq.push(2);
pq.push(1);

Min Heap elements: 1 2 3 4 5


🔹Syntax for Min Heap with Pairs (pair<int, int>)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

------Breakdown:
pair<int, int>
The priority queue will store elements of type pair<int, int>.
The first value (int) is the actual number.
The second value (int) is the index of that number in the array.

vector<pair<int, int>>
The underlying container of the heap is a vector.
This means the heap will internally store elements in a vector<pair<int, int>>.

greater<pair<int, int>>
This changes the default behavior of priority_queue to a Min Heap.
greater<pair<int, int>> makes sure that the smallest element comes first instead of the largest.

e.g
pq.push({1, 2});
pq.push({2, 3});
pq.push({5, 6});
pq.push({3, 4});

Min Heap of Pairs: {1,2} {2,3} {3,4} {5,6}

Time Complexity Analysis : 
Each element is inserted once into the heap → O(n log n)
Each element is removed at most once → O(n log n)
Overall complexity → O(n log n)

Insertion - O(log N)
Deletion -	O(log N)
Access Top	- O(1)
Size  - O(1)
Check Empty - 	O(1)


--------------------------------------------------------------------------------------
1. bisect_left() and bisect_right() in Python : 

a) bisect_left(arr, x) - 
Finds the leftmost insertion index of x in the sorted list arr.
If x is already present, it returns the index of the first occurrence.

import bisect
arr = [1, 3, 3, 3, 5, 6, 8]
x = 3
index = bisect.bisect_left(arr, x)
print(index)  # Output: 1 (first occurrence of 3 is at index 1)


b) bisect_right(arr, x)
Finds the rightmost insertion index of x in the sorted list arr.
If x is already present, it returns the index after the last occurrence.

import bisect
arr = [1, 3, 3, 3, 5, 6, 8]
x = 3
index = bisect.bisect_right(arr, x)
print(index)  # Output: 4 (just after the last occurrence of 3)

Time Complexity
bisect_left()	O(log N)
bisect_right()	O(log N)




2. C++ Equivalent: lower_bound() and upper_bound()

lower_bound(arr.begin(), arr.end(), x) - arr.begin()
upper_bound(arr.begin(), arr.end(), x) - arr.begin()

vector<int> arr = {1, 3, 3, 3, 5, 6, 8};
int x = 3;

// lower_bound() is equivalent to bisect_left()
int left_index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
cout << "Lower Bound (bisect_left) index: " << left_index << endl; // Output: 1

// upper_bound() is equivalent to bisect_right()
int right_index = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
cout << "Upper Bound (bisect_right) index: " << right_index << endl; // Output: 4




Q. When to Use bisect in Python?
Efficiently Searching for Insert Positions: If you need to find where to insert an element in a sorted array.
Finding Range of a Number: If you need to determine the first and last occurrence of an element.


Summary
1. bisect_left(arr, x): Finds the first occurrence or insertion index of x.
2. bisect_right(arr, x): Finds the last occurrence or insertion index of x.
3. lower_bound() in C++ is equivalent to bisect_left().
4. upper_bound() in C++ is equivalent to bisect_right().
5. Both run in O(log N) time complexity.
Used for efficient range searching and sorted insertions.






