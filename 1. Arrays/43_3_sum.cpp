#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void triplet(int arr[], int n, int target){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int low=i+1;
        int high=n-1;
        int sum=target-arr[i];
        while(low<high){
            if (arr[low]+arr[high]==sum){
                cout<<arr[i]<<" "<<arr[low]<<" "<<arr[high]<<endl;
                return;
            }
            else if(arr[low]+arr[high]<sum){
                low++;
            }
            else{
                high--;
            }

        }
    }
    cout<<"-1"<<endl;

}

int main(){
    int n=6;
    int arr[n]={12,3,7,1,6,9,11,8,6};
    int target =24;
    triplet(arr,n,target);
}