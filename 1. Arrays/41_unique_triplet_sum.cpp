// All unique triplet 
// time complexity O(n^2)

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void triplet(int arr[], int n, int target){
    sort(arr,arr+n);
    vector<vector<int>>v;
    for(int i=0;i<n-2;i++){
        if(i==0 or (i>0 and arr[i]!=arr[i-1]))
        {
            int low=i+1;
            int high=n-1;
            int sum=target-arr[i];
            
            while(low<high){
                if (arr[low]+arr[high]==sum){
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    v.push_back(temp);

                    while(low<high and arr[low]==arr[low+1]){
                        low++;
                    }
                    while(low<high and arr[high]==arr[high+1]){
                        high--;
                    }

                    low++;
                    high--;
                    
                }
                else if(arr[low]+arr[high]<sum){
                    low++;
                }
                else{
                    high--;
                }

            }
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}

int main(){
    int n=6;
    int arr[n]={-1,0,1,2,-1,-4};
    int target =0;

    // int arr[n]={12,3,7,1,6,9};
    // int target =24;

    // int n=11;
    // int arr[n]={-2,-2,-1,-1,-1,0,0,0,2,2,2};
    // int target =6;
    triplet(arr,n,target);
}