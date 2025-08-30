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