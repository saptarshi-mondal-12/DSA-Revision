#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Minimum days to make m bouquet

You are given an integer array bloomDay, an integer m and an integer k.You want to make m bouquets. 
To make a bouquet, you need to use k adjacent flowers from the garden. The garden consists of n flowers, 
the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
If it is impossible to make m bouquets return -1.

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is 
impossible to get the needed bouquets and we return -1.

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three 
flowers that bloomed because they are not adjacent. After day 12: [x, x, x, x, x, x, x] It is obvious that we can make two bouquets in different ways.
*/

bool possible(int n, vector<int>arr, int m, int k, int day){
    int noOfBouquets=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day){
            count++;
        }else{
            noOfBouquets+=(count/k);
            count=0;
        }
    }
    noOfBouquets+=(count/k);

    if(noOfBouquets>=m){
        return true;
    }
    return false;
}

int brute_minDays(int n, vector<int>arr, int m, int k){
    // TC = O(maxi-mini+1) * O(n)
    // SC = O(1)

    long long v = static_cast<long long>(m) * k;
    if(v > n) return -1;

    int mini=*min_element(arr.begin(),arr.end());
    int maxi=*max_element(arr.begin(),arr.end());

    for(int day=mini;day<=maxi;day++){
        if(possible(n,arr,m,k,day)){
            return day;
        }
    }
    return -1;
}

int optimal_minDays(int n, vector<int>arr, int m, int k){
    // tc = O()
    // sc = O(1)

    if(m*k > n) return -1;

    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(possible(n,arr,m,k,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n=7;
    vector<int>arr={7,7,7,7,12,7,7};
    int m=2;
    int k=3;

    // brute 
    cout<<brute_minDays(n,arr,m,k)<<endl;

    // optimal
    cout<<optimal_minDays(n,arr,m,k)<<endl;

}
