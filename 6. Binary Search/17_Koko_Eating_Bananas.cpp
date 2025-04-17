#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  Koko Eating Bananas

A monkey is given ‘n’ piles of bananas, whereas the ‘ith’ pile has ‘a[i]’ bananas. 
An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. 
If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas 
and won’t eat any more bananas in that hour. Find the minimum number of bananas ‘k’ to eat per hour 
so that the monkey can eat all the bananas within ‘h’ hours.

Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
Result: 5
Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. 
So, he will take 8 hours to complete all the piles.  

Example 2:
Input Format: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
Result: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat 
the piles accordingly. So, he will take 5 hours to complete all the piles.
*/

int findMax(int n, int arr[]){
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    return ans;
}

void brute_koko(int n, int arr[], int h){
    // TC = O(n + n^2)
    // SC = O(1)

    int maxi=findMax(n,arr);
    int ans=0;
    for(int i=1;i<=maxi;i++){
        int time=0;
        for(int j=0;j<n;j++){
            if(arr[j]%i==0){
                time+=arr[j]/i;
            }else{
                time+=(arr[j]/i) +1;
            }
        }
        if (time<=h){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;  
}

long long compute(int n ,int arr[], int mid){
    long long totalHour=0;
    for(int i=0;i<n;i++){
        if(arr[i]%mid == 0){
            totalHour+=(arr[i]/mid);
        }else{
            totalHour+=(arr[i]/mid)+1;
        }
    }
    return totalHour;
}

void optimal_koko(int n, int arr[], int h){
    // TC = O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
    // SC = O(1)

    int low=1, high=findMax(n,arr);
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        long long total_time=compute(n,arr,mid);

        if (total_time <= h){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}


int main(){
    int n=5;
    int h=5;
    int arr[n]={25, 12, 8, 14, 19};

    // int n=4;
    // int h=8;
    // int arr[n]={7, 15, 6, 3};

    // 1. brute 
    brute_koko(n,arr,h);

    // 2. optimal - binary search
    optimal_koko(n,arr,h);
}
