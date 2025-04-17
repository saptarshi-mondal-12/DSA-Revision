#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Input: people = [1,2], limit = 3
Output: 1 
Explanation: 1 boat (1, 2)

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/

int numRescueBoats(vector<int>people, int limit){
    int n=people.size();
    int trip=0;
    int low=0;
    int high=n-1;

    sort(people.begin(), people.end());

    while(low<high){
        if(people[low]+people[high] <= limit){
            trip+=1;
            low+=1;
            high-=1;
        }
        else if(people[low]+people[high] > limit){
            high-=1;
            trip+=1;
        }
    }
    if(low==high){
        trip+=1;
    }
    return trip;
}

int main(){
    vector<int>nums={3,2,2,1};
    int limit=3;
    cout<<numRescueBoats(nums,limit);
}