#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Divide Players Into Teams of Equal Skill

You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6. The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.

Input: skill = [3,4]
Output: 12
Explanation: The two players form a team with a total skill of 7. The chemistry of the team is 3 * 4 = 12.

Input: skill = [1,1,2,3]
Output: -1
Explanation: There is no way to divide the players into teams such that the total skill of each team is equal.
*/

long long dividePlayers(vector<int>& skill) {
    int n=skill.size();
    sort(skill.begin(), skill.end());
    int noOfTeams=n/2;
    long long totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=skill[i];
    }
    long long target=totalSum/noOfTeams;
    int i=0, j=n-1;
    int count=0;
    long long result=0;
    while (i<j){
        if (skill[i]+skill[j] == target){
            result+=skill[i]*skill[j];
            i++;
            j--;
            count++;
        }else if (skill[i]+skill[j] > target){
            j-=1;
        }else{
            i++;
        }
    }
    if(count==noOfTeams){
        return result;
    }
    return -1; 
}



int main(){
    vector<int>skill={3,2,5,1,3,4};
    cout<<dividePlayers(skill);
}