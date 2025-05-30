#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Minimum time taken by each job to be completed given by a Directed Acyclic Graph

Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by job to be completed where each Job takes unit time to get completed.


Input: N=10, M=13
edges[]={{1,3},{1,4},{1,5},{2,3},{2,8},{2,9},{3,6},{4,6},{4,8},{5,8},{6,7},{7,8},{8,10}}
Output: time[]={1,1,2,2,2,3,4,5,2,6 }
Explanation: Start jobs 1 and 2 at the beginning and complete them at 1 unit of time.
Since, all the jobs on which need to be completed before the jobs 3, 4, 5, and 9 are completed. So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly,
Job 6 can only be done after the 3rd and 4th jobs are done. So, start it at the 2nd unit of time and complete it at the 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at the 3rd unit of time and complete it at the 4th unit of time.
Job 8 can only be done after the 4th, 5th, and 7th jobs are done. So, start it at the 4th unit of time and complete it at the 5th unit of time.
Job 10 can only be done after the 8th job is done. So, start it at the 5th unit of time and complete it at the 6th unit of time.
*/

vector<int> minimumTime(int n, vector<vector<int>> &edges, int m){
    // Time complexity:

    // creating adjacency list;
    vector<vector<int>> adjacency_List(n + 1);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0] - 1; // convert to 0-based
        int v = edges[i][1] - 1; // convert to 0-based
        adjacency_List[u].push_back(v);
    }

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++){
        for (auto it : adjacency_List[i]){
            indegree[it]++;
        }
    }

    vector<int> minimumTimeJob(n, 0);

    // Pushing all 0 indegree to queue and
    // Update the time of the jobs who don't require any job to be completed before this job
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (indegree[i] == 0){
            q.push(i);
            minimumTimeJob[i] = 1;
        }
    }

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (auto it : adjacency_List[node]){
            // Decrease in-degree of the current node
            indegree[it]--;
            if (indegree[it] == 0){
                minimumTimeJob[it] = minimumTimeJob[node] + 1;
                q.push(it);
            }
        }
    }

    return minimumTimeJob;
}

int main(){
    int n = 10, m = 13;
    vector<vector<int>> edges = {
        {1,3},{1,4},{1,5},
        {2,3},{2,8},{2,9},
        {3,6},{4,6},{4,8},
        {5,8},{6,7},{7,8},{8,10}};

        vector<int>ans=minimumTime(n,edges,m);
        for(auto it: ans){
            cout<<it<<" ";
        }
}