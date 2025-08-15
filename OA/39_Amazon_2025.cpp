#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Online Election - Most Important AMAZON 2025

You are given two integer arrays persons and times. In an election, the ith vote was cast for persons[i] at time times[i].

For each query at a time t, find the person that was leading the election at time t. Votes cast at time t will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.

Implement the TopVotedCandidate class:

TopVotedCandidate(int[] persons, int[] times) Initializes the object with the persons and times arrays.
int q(int t) Returns the number of the person that was leading the election at time t according to the mentioned rules.

Example 1: 

Input:["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]

Output: [null, 0, 1, 1, 0, 0, 1]

Explanation:
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // return 0, At time 3, the votes are [0], and 0 is leading.
topVotedCandidate.q(12); // return 1, At time 12, the votes are [0,1,1], and 1 is leading.
topVotedCandidate.q(25); // return 1, At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
topVotedCandidate.q(15); // return 0
topVotedCandidate.q(24); // return 0
topVotedCandidate.q(8); // return 1

*/

class TopVotedCandidate {
public:
    vector<int>leaderBoard;
    vector<int>timeTable;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n=persons.size();
        vector<int>votes(n, 0);

        int maxVotes=0;
        int leadingPerson=0;

        for(int i=0;i<n;i++){
            votes[persons[i]]++;

            if(votes[persons[i]] >= maxVotes){
                maxVotes=votes[persons[i]];
                leadingPerson=persons[i];
            }
            leaderBoard.push_back(leadingPerson);
            timeTable.push_back(times[i]);
        }
    }
    
    int q(int t) {
        int leadingPerson = -1;
        int low=0, high=leaderBoard.size()-1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if(timeTable[mid] == t){
                leadingPerson=mid;
                return leaderBoard[leadingPerson];
            }
            else if (timeTable[mid] < t) {
                leadingPerson = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return leaderBoard[leadingPerson];
    }
};


int main(){
    vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    vector<int> times    = {0, 5, 10, 15, 20, 25, 30};

    TopVotedCandidate s(persons, times);

    vector<int> queries = {3, 12, 25, 15, 24, 8};
    for (int t : queries) {
        cout << s.q(t) << " ";
    }

}