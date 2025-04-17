#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Leaders in an Array
 Given an array, print all the elements which are leaders. A Leader is an element that is 
 greater than all of the elements on its right side in the array.

Input: arr = [4, 7, 1, 0]
Output: 7 1 0
Explanation: Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Input: arr = [10, 22, 12, 3, 0, 6]
Output: 22 12 6
Explanation: 6 is a leader. In addition to that, 12 is greater than all the elements in 
its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.*/

void brute_Leader(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(n)

    vector<int> leader;

    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=i+1;j<n;j++){
            if (arr[j]>=arr[i]){
                flag=false;
                break;
            }
        }
        if (flag){
            leader.push_back(arr[i]);
        }
    }

    for(auto it:leader) cout<<it<<" ";
    cout<<endl;
}

void optimal_Leader(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(n)

    int mx=INT_MIN;
    vector<int>result;

    for(int i=n-1;i>=0;i--){

        if (arr[i]>mx){
            result.push_back(arr[i]);
        }
        // keep track of right maximum
        mx=max(mx,arr[i]);
    }

    for(int i=result.size()-1;i>=0;i--) cout<<result[i]<<" ";
    cout<<endl;

}


int main(){
    int n=6;
    int arr[n]={10,22,12,3,0,6};

    // 1. brute
    brute_Leader(n,arr);

    // 2. Optimal
    optimal_Leader(n,arr);

}