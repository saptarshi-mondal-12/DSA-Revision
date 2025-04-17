#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Aggressive Cows

You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows. You are given the task of assigning 
stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.

Find the maximum possible minimum distance.

Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result: 3
Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are 
placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. 
We cannot make the minimum distance greater than 3 in any ways.

Input Format: N = 5, k = 2, arr[] = {4,2,1,3,6}
Result: 5
Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}. 
*/

/* Intuition - (min distance between cows) is max

1. sort the stall (because of minimum distance)

2. minimum distance will be always between two sorted consecutive no i.e we have to sort the array to find minimum 

trying to keep minimum distance 1
0 3 4 7 9 10
1 2 3 4 - (1,2 -> 3) (2,3 -> 1) (3,4 -> 3) (1,3 -> 4) (2,4 -> 4) (1,4 -> 7) = minimum Distance between cow is (3,1,3,4,4,7)=1 

trying to keep minimum distance 2
0 3 4 7 9 10
1 2   3 4 - (1,2 -> 3) (2,3 -> 4) (3,4 -> 2) (1,3 -> 7) (2,4 -> 6) (1,4 -> 9) = minimum Distance between cow is (3,4,2,7,6,9)=2

trying to keep minimum distance 3
0 3 4 7 9 10
1 2   3    4 - (1,2 -> 3) (2,3 -> 4) (3,4 -> 3) (1,3 -> 7) (2,4 -> 7) (1,4 -> 10) = minimum Distance between cow is (3,4,3,7,7,10)=3 

trying to keep minimum distance 4
0 3 4 7 9 10
1   2   3     maintain distance 4 but not able to place 4 cows 


NOTE - MINIMUM DISTANCE WILL BE ALWAYS CONSECUTIVE NO

Answer = min(max) = (1,2,3) = 3

[1, max-min] ans will always between range

*/

bool possible(int n, vector<int>arr, int k, int distance){
    int cows=1; 
    int last=arr[0];
    for(int i=1;i<n;i++){
        if (arr[i]-last >= distance){
            cows+=1;
            last=arr[i];
        }
    }
    if(cows>=k) return true;
    return false;
}

void brute_aggressiveCows(int n, vector<int>arr, int k){
    // TC = O(max-min) * O(n)
    // SC = O(1)

    sort(arr.begin(),arr.end());

    int mini=*min_element(arr.begin(),arr.end());
    int maxi=*max_element(arr.begin(),arr.end());

    int ans=-1;

    for(int i=1;i<=(maxi-mini);i++){
        if(possible(n,arr,k,i)){
            continue; 
        }
        else{
            ans=i-1;
            break;
        }
    }
    cout<<ans<<endl; 
}

void optimal_aggressiveCows(int n, vector<int>arr, int k){
    // TC = O(log n)
    // SC = O(1)

    sort(arr.begin(),arr.end());

    int mini=*min_element(arr.begin(),arr.end());
    int maxi=*max_element(arr.begin(),arr.end());

    int ans=-1;

    int low=0; 
    int high = maxi-mini;
    while(low<=high){
        int mid=(low+high)/2;

        if(possible(n,arr,k,mid)){
            ans=mid;
            low=mid+1;
            
        }else{
            high=mid-1;
        }
    }
    cout<<ans<<endl; 
}

int main(){

    int n=6;
    vector<int>arr={0,3,4,7,10,9};
    int k=4;

    // brute 
    brute_aggressiveCows(n,arr,k);

    // optimal 
    optimal_aggressiveCows(n,arr,k);
}