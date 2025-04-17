#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// Find all numbers that appear more than 1
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3] 


vector<int> findDuplicates(int arr[], int n){
    // brute
    // Time complexity - O(n) + O(m*n)
    // space complexity - O(m)

    // vector<int> result;
    // set<int>st;

    // for(int i=0;i<n;i++){
    //     st.insert(arr[i]); 
    // }
    // for(auto it: st){
    //     int num=it;
    //     int count=0;
    //     for(int j=0;j<n;j++){
    //         if (num==arr[j]) count++;
    //     }
    //     if(count>1) result.push_back(num);
    // }
    // return result;




    // optimal
    // Time complexity - O(n) + O(n) = O(2n)
    // space complexity - O(n)

    vector<int>result;
    map<int, int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if (it.second > 1){
            result.push_back(it.first);
        }
    }
    return result;


}


int main(){
    int n=8;
    int arr[n]={4,3,2,7,8,2,3,1};
    vector<int>duplicates=findDuplicates(arr,n);
    for(int i=0;i<duplicates.size();i++) cout<<duplicates[i]<<' ';
}