#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 3 Sum 
Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. 
In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that 
i!=j, j!=k, k!=i, and their sum is equal to zero.

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums=[-1,0,1,0]
Output: Output: [[-1,0,1],[-1,1,0]]
*/

vector<vector<int>> brute_triplet(int n, int arr[]){
    // Time complexity - O(n^3)
    // space complexity -O(2* no. of the unique triplets) 

    set<vector<int>>st;

    for(int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}

vector<vector<int>> better_triplet(int n, int arr[]){
    /* Time complexity -  O(N^2 * log(no. of unique triplets))
       space complexity - O(2 * no. of the unique triplets) + O(N) because we are using a set data structure and a list to store the triple
       and extra O(N) for storing the array elements in another set.*/

    set<vector<int>> st;

    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(arr[i]+arr[j]);

            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={arr[i],arr[j], third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}

vector<vector<int>> optimal_triplet(int n, int arr[]){
    // Time complexity - O(n log n) + O(n^2) 
    // space complexity - O(3) = O(1)

    sort(arr,arr+n);
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if (i>0 && arr[i]==arr[i-1]){
            continue;
        }
        int j=i+1;
        int k=n-1;

        while (j < k){

            int total=arr[i]+arr[j]+arr[k];

            if(total==0){
                j++;
                k--;
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);

                // skipping duplicates
                while (j<k && arr[j]==arr[j-1]) j++;
                while (j<k && arr[k]==arr[k+1]) k--;
            }
            else if (total < 0){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return ans;
}


int main(){
    int n=6;
    int arr[n]={-1,0,1,2,-1,-4};

    // int n=12;
    // int arr[n]={-2,-2,-2,-1,-1,-1,0,0,0,2,2,2};

    // 1. Brute 
    // vector<vector<int>> ans = brute_triplet(n, arr);

    // 2. Better
    // vector<vector<int>> ans = better_triplet(n, arr);

    // 3. optimal
    vector<vector<int>> ans = optimal_triplet(n, arr);

    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
}