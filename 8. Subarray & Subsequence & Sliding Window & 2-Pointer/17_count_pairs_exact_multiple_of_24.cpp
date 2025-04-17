#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count Pairs That Form a Complete Day II

Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.
A complete day is defined as a time duration that is an exact multiple of 24 hours.
For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

Input: hours = [12,12,30,24,24]
Output: 2
Explanation: The pairs of indices that form a complete day are (0, 1) and (3, 4).


Input: hours = [72,48,24,3]
Output: 3
Explanation: The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2)

Input: hours = [10,21,27]
Output: 1
*/


int brute_countCompleteDayPairs(vector<int>hours){
    // Time complexity - O(n^2)
    // space complexity - O(1)
    int n=hours.size();
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((hours[i]+hours[j]) % 24 == 0){
                result++;
            }
        }
    }
    return result;
}

int optimal_countCompleteDayPairs(vector<int>hours){
    // Time complexity - O(n)
    // space complexity - O(n)
    int n=hours.size();
    unordered_map<int,int>mp;
    int result=0;
    for(int i=0;i<n;i++){
        int mod=hours[i]%24;
        int target=(24-mod)%24;

        if(mp.find(target)!=mp.end()){
            result+=mp[target];
        }

        mp[mod]+=1;
    }
    return result;
}

int main(){
    vector<int>v={12,12,30,24,24};

    cout<<brute_countCompleteDayPairs(v)<<endl;
    cout<<optimal_countCompleteDayPairs(v)<<endl;
}
