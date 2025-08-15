#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Log {
    int time;
    string user;
    string room;
    string action;
};

vector<string>getAllInfectedPersons(vector<Log> logs, string infectedPerson){

    set<string> names;

    // Step 1: Store entry and exit times per user
    unordered_map<string, vector<pair<int,int>>> userIntervals;
    unordered_map<string, int> entryTime;

    for(int i=0;i<logs.size();i++){
        int time = logs[i].time;
        string user = logs[i].user;
        string action = logs[i].action;

        if(action == "enter"){
            entryTime[user] = time;
        }else{
            int start = entryTime[user];
            int end = time;
            userIntervals[user].push_back({start, end});
        }

    }

    // Step 2: Get infected user intervals
    vector<pair<int,int>> infectedIntervals = userIntervals[infectedPerson];



    // Step 3: For every other user, check if any of their intervals overlap with the infected person's intervals
    for(auto it: userIntervals){
        string user=it.first;

        if(user == infectedPerson) continue;

        vector<pair<int,int>>intervals=it.second;
        for(auto it2: intervals){
            int userEntryTime=it2.first;
            int userExitTime=it2.second;


            // check with infected person
            for(auto it3: infectedIntervals){
                int infectedEntryTime=it3.first;
                int infectedExitTime=it3.second;

                if(userEntryTime <= infectedExitTime && infectedEntryTime <= userExitTime){
                    names.insert(user);
                    break;
                }
            }
        }
        
    }

    vector<string>all_Infected_Names(names.begin(), names.end());
    return all_Infected_Names;
}


int main() {
    vector<Log> logs = {
        {0, "Navi", "meetingRoomA", "enter"},
        {5, "jeff", "meetingRoomA", "enter"},
        {10, "Navi", "meetingRoomA", "exit"},
        {15, "jeff", "meetingRoomA", "exit"}
    };

    string infectedPerson= "jeff";

    vector<string>names=getAllInfectedPersons(logs, infectedPerson);
    for(auto it: names){
        cout<<it<<" ";
    }

}