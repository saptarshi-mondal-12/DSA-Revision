#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 4 Sum

Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

*/

vector<vector<int>> brute_4Sum(int n, int arr[], int target){
    // Time complexity - O(n^4)
    // space complexity - O(2*  no. of the quadruplets)
    
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1; k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long total=arr[i]+arr[j]+arr[k]+arr[l];
                    if(total==target){
                        vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> result(st.begin(),st.end());
    return result;

}

vector<vector<int>> better_4Sum(int n, int arr[], int target){
    // Time complexity - O(n^3 * log(m)) 
    // space complexity - O(n) + O(quads)*2

    set<vector<int>>st;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int>hashset;
            for(int k=j+1;k<n;k++){
                int sum=arr[i]+arr[j]+arr[k];
                int fourth=target-sum;

                if(hashset.find(fourth)!=hashset.end()){
                    vector<int>temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> result(st.begin(),st.end());
    return result; 

}

vector<vector<int>> optimal_4Sum(int n, int arr[], int target){
    // Time complexity - O(n^2 * n) = O(n^3)
    // space complexity -O(no. of quadruplets)

    sort(arr,arr+n);
    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        
        for(int j=i+1;j<n;j++){
            if (j!=i+1 && arr[j]==arr[j-1]) continue;

            int k=j+1;
            int l=n-1;
            
            while (k<l){
                int sum=arr[i]+arr[j]+arr[k]+arr[l];

                if(sum==target){
                    vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);

                    k++;
                    l--;

                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(l>k && arr[l]==arr[l+1]) l--;

                }
                else if(sum < target){
                    k++;
                }
                else{
                    l--;
                }
            }  
        }
    }
    return ans;  
}


int main(){

    // int n=10;
    // int arr[n]={4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    // int target=9;

    int n=4;
    int arr[n]={1000000000,1000000000,1000000000,1000000000};
    int target=-294967296;

    // 1. Brute 
    // vector<vector<int>> ans = brute_4Sum(n, arr, target);

    // 2. Better
    // vector<vector<int>> ans = better_4Sum(n, arr, target);

    // 3. optimal
    vector<vector<int>> ans = optimal_4Sum(n, arr, target);

    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    
}