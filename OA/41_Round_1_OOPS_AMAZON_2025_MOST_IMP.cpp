#include<bits/stdc++.h>
using namespace std;

/* Q. AMAZON 2025 Round 1 Question 

1. OOPs Implementation Question
Given student data with fields: rollNo (alphanumeric and unique), marks, name, rank (not unique), etc.
Task:

Write classes and functions to:
    1. Retrieve all students for a given rank.
    2. Retrieve a student by their roll number.

-----------------------------------------------------------------------------------------------------------------------

✅ How to Explain to the Interviewer
🔹 1. Clarify the Requirement

“We need to store student information (roll number, name, marks, rank) and support two operations:

    Retrieve all students for a given rank.
    Retrieve a student’s full details by their roll number.”
    Roll number is unique → natural choice for a key.
    Rank can be shared by multiple students → need a way to store multiple names per rank.
    Student details (name, marks, rank) can be grouped into a struct.

🔹 2. Data Structure Choice

“I’ll use two hash maps (unordered_map) because we need fast lookups.”

unordered_map<string, Student> studentDetails;
Key = roll number (unique)
Value = Student struct containing name, marks, rank
unordered_map<int, vector<string>> rankDetails;
Key = rank (not unique)
Value = list of student names with that rank


Why unordered_map instead of map?

    unordered_map gives average O(1) lookup, insertion, deletion (better than O(log n) in map for large datasets).
    Roll number is unique → best as key.
    Rank may repeat → store multiple values in a vector.

🔹 3. Implementation Outline

    Define a Student struct with fields: name, marks, rank.
    Maintain two maps: one for quick lookup by roll number, another for lookup by rank.
    Functions:
        insert_newStudent(rollNo, name, marks, rank) → insert student into both maps.
        printStudentDetailsByRollNo(rollNo) → retrieve details by roll number.

-----------------------------------------------------------------------------------------

Follow up Questions --------

Q1. How does HashMap / unordered_map work internally?
Ans: A HashMap (Java) / unordered_map (C++) is implemented using a hash table.
    a) It uses an array of buckets internally.

    b) Each key is passed to a hash function, which converts it into an index (bucket number).

    c) Keys that hash to the same bucket are handled using collision resolution techniques (like chaining with linked lists or open addressing).

    d) Lookup, insertion, and deletion are O(1) average case, but O(n) worst case if many collisions occur.

    e) The container resizes itself (rehashing) when the load factor (items / buckets) crosses a threshold.


Q2. What is a hash function and why is it important?
Ans: A hash function is a function that converts a given key into an index in the bucket array.
A good hash function distributes keys uniformly across buckets to avoid collisions.

Example: rolling hash, polynomial hash.
In unordered_map, the default is std::hash<T>.



Q3. What happens when two keys collide?
Ans: When two keys collide (i.e., they hash to the same index), the hash table must handle this situation because both keys cannot occupy the same slot directly. 

So, when two keys collide, they are stored in the same bucket. Depending on the implementation, that bucket might hold a linked list of entries or a tree structure to maintain efficient lookup time even under heavy collision scenarios.



Q3. What are collisions and how are they handled?
Ans: A collision occurs when two keys hash to the same bucket.

Handling techniques:
    a) Chaining (linked list or balanced tree per bucket).
    b) Open addressing (linear probing, quadratic probing, double hashing).
    c) In unordered_map, chaining with linked list or tree is used.


    
Q4. What is load factor and rehashing?
Ans: “Load factor = size / number of buckets. It measures how full the table is. If it exceeds a threshold (usually 0.75), the table is resized to maintain O(1) average time.”
    a) When load factor exceeds a threshold (usually 0.75), the table is resized (rehash).
    b) Rehashing: create a bigger bucket array and reinsert all elements using the new hash function.
    c) Guarantees average-case O(1) even as data grows.


Q5. Why not use map instead of unordered_map?
Ans: map → implemented as Red-Black Tree (balanced BST) → O(log n) operations.
unordered_map → implemented as hash table → average O(1).
Use map if you need sorted order traversal; use unordered_map if you need fast lookups.


Q6. Can unordered_map have duplicate keys?
Ans: No, keys must be unique. If we need duplicates → use unordered_multimap.


Q7. What is the worst-case time complexity of unordered_map operations?
Ans: O(n) in worst case (when all elements collide into the same bucket).
But with good hash functions + rehashing, average O(1) is achieved.


Q8. How is the hash function chosen in C++ unordered_map / Java HashMap?
Ans: In C++: default is std::hash<T>.



Q9. What makes a good hash function?
Ans: “A good hash function should distribute keys uniformly, avoid clustering, and be fast to compute. This minimizes collisions and keeps lookup O(1) on average.”



Q10. What exactly happens when two keys collide in the same bucket?
Ans: In C++ unordered_map: uses chaining (linked list, and in some implementations tree if the list grows too long).



Q11. What’s the role of the load factor?
Ans: Defines how full the hash table can get before resizing.
Typical threshold: 0.75.
Keeps average case O(1).


Q12. Why not keep load factor = 1 to save memory?
Ans: If load factor is too high, many collisions occur and buckets get long. That degrades performance toward O(n). Lower load factors balance memory usage and speed.



Q13. Explain rehashing in detail.
Ans: “Rehashing happens when the load factor exceeds a threshold. A bigger bucket array is created (often 2x size), and all keys are re-hashed into it. It’s O(n) when it occurs but amortized O(1) per insertion.” When threshold exceeded: new array of ~2x buckets created. Each existing key is re-hashed and redistributed.
Costly (O(n)) when it happens, but rare → amortized still O(1).


Q14. Can rehashing be avoided?
Ans: “Not completely, but we can minimize it by reserving capacity upfront (reserve() in C++ / initialCapacity in Java) if we know data size in advance.”


Q15. Difference between map vs unordered_map.
Ans: “map is implemented as a balanced tree, giving O(log n) operations with sorted order. unordered_map is a hash table, giving O(1) average operations but no ordering. I’d choose map if ordering matters, otherwise unordered_map.”

map: Red-Black tree, O(log n), ordered.
unordered_map: hash table, O(1) avg, unordered.


Q16. When would you prefer map over unordered_map?
Ans: “I’d prefer map when I need ordered traversal of elements or when I need to maintain a sorted order. It’s also useful when keys are not easily hashable.”


Q17. Worst-case complexity of hashmap?
Ans: “Worst case is O(n) if all keys hash into the same bucket. With balanced trees (like Java 8), it becomes O(log n). But with good hash functions and rehashing, average case stays O(1).”


*/


struct Student {
    string name;
    int marks;
    int rank;
};

class StudentDB {
public:
    unordered_map<int, vector<string>> rankDetails;
    unordered_map<string, Student> studentDetails;

    void insert_newStudent(string rollNo, string name, int marks, int rank) {
        // 1. link rank with student name
        rankDetails[rank].push_back(name);

        // 2. store full student details
        studentDetails[rollNo] = {name, marks, rank};
    }

    // 1. Retrieve all students for a given rank
    void printStudentDetailsByRank(int rank) {
        if (rankDetails.find(rank) != rankDetails.end()) {
            for (auto &nm : rankDetails[rank]) {
                cout << nm << ", ";
            }
            cout << endl;
        } else {
            cout << "No students found for rank " << rank << endl;
        }
    }

    // 2. Retrieve a student details by their roll number
    void printStudentDetailsByRollNo(string rollNo) {
        auto it = studentDetails.find(rollNo);
        if (it != studentDetails.end()) {
            cout << "Roll: " << it->first << endl;
            cout << "Name: " << it->second.name << endl;
            cout << "Marks: " << it->second.marks << endl;
            cout << "Rank: " << it->second.rank << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }
};

int main() {
    StudentDB s;

    s.insert_newStudent("CS101", "Saptarshi", 499, 1);
    s.insert_newStudent("CS102", "Shivani", 499, 1);
    s.insert_newStudent("CS112", "Ishika", 499, 1);
    s.insert_newStudent("CS150", "Anurag", 450, 2);
    s.insert_newStudent("CS111", "Srijan", 402, 3);

    cout << "--- Students with Rank 1 ---" << endl;
    s.printStudentDetailsByRank(1);

    cout << "\n--- Student details: RollNo = CS101 ---" << endl;
    s.printStudentDetailsByRollNo("CS101");
}