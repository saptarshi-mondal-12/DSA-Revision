#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int brute_row_with_max_ones(vector<vector<int>> matrix){
    // time complexity - O(n * m)
    // space complexity - O(1)

    int n=matrix.size();
    int m=matrix[0].size();

    int answer=-1;
    int row=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1){
                count++;
            }
        }
        if(count > answer){
            answer=count;
            row=i;
        }
    }
    return row;
}


int optimal_row_with_max_ones(vector<vector<int>> matrix){
    // time complexity - O(n * log m)
    // space complexity - O(1)

    // approach - lower bound of 1

    int n=matrix.size();
    int m=matrix[0].size();
    int maxOne=-1;
    int ans=-1;

    for(int i=0;i<n;i++){

        int low=0, high=m-1;
        int lowerBoundOfOne=m;

        while (low<=high){
            int mid=(low+high)/2;

            if(matrix[i][mid]==1){
                lowerBoundOfOne=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        int count=m-lowerBoundOfOne;

        if (count > maxOne){
            maxOne=count;
            ans=i;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};

    // 1. brute 
    cout<<brute_row_with_max_ones(matrix)<<endl;

    // 2. optimal 
    cout<<optimal_row_with_max_ones(matrix)<<endl;

}
