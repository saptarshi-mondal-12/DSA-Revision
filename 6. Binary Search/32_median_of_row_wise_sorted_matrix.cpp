#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute_median(vector<vector<int>> matrix){
    // time complexity - O(n*m) + (n*m * log(n*m))
    // space complexity - O(n*m)

    int n=matrix.size();
    int m=matrix[0].size();

    vector<int> nums;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            nums.push_back(matrix[i][j]);
        }
    }
    sort(nums.begin(),nums.end());
    return nums[(n*m)/2];
}



int main(){
    vector<vector<int>> matrix={{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};

    // 1. brute 
    cout<<brute_median(matrix)<<endl;
}