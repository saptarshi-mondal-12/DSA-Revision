#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute_Merge(int n, int arr1[], int m, int arr2[]){
    // Time complexity - O(n+m) + O(n+m)
    // space complexity - O(n+m)

    vector<int> ans;

    int i=0, j=0;
    while (i<n and j<m){
        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while (i<n){
        ans.push_back(arr1[i]);
        i++;
    }

    while (j<m){
        ans.push_back(arr2[j]);
        j++;
    }

    for(int i=0;i<n+m;i++){
        if(i<n){
            arr1[i]=ans[i];
        }else{
            arr2[i-n]=ans[i];
        }
    }
}

void optimal_Merge(int n, int arr1[], int m, int arr2[]){
    // Time complexity - O(min(m,n)) + O(n log n) + O(m log m)
    // space complexity - O(1)

    int i=n-1;
    int j=0;

    while (i>=0 && j<m){
        if(arr1[i] >= arr2[j]){
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}



int main(){
    int n=4,m=5;
    int arr1[n]={1,3,5,7};
    int arr2[m]={0,2,6,8,9};

    // 1. brute
    // brute_Merge(n,arr1,m,arr2);

    // 2. optimal
    optimal_Merge(n,arr1,m,arr2);

    
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

}