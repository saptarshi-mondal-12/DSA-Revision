#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Capacity to ship packages within d days -

A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with 
packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10


Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/

int findDays(int n, vector<int>weights, int capacity){
    int days=1;
    int load=0;
    for(int i=0;i<n;i++){
        if(load+weights[i] <= capacity){
            load+=weights[i];
        }else{
            days+=1;
            load=weights[i];
        }
    }
    return days;
}

void brute_leastWeightCapacity(int n, vector<int>weights, int days){
    // TC = O(N * (sum(weights[]) – max(weights[]) + 1))
    // SC = O(1)

    int maxi=*max_element(weights.begin(),weights.end());
    int sum=accumulate(weights.begin(),weights.end(),0);
    int ans=-1;

    for(int i=maxi;i<=sum;i++){
        if(findDays(n,weights,i) <= days){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}

void optimal_leastWeightCapacity(int n, vector<int>weights, int days){
    // TC =  O(N * log(sum(weights[]) – max(weights[]) + 1))

    // if we take capacity of 4 we cannot ship 5 & 6 weight, if we take 6 as minimum capacity we can shipped all packages
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(findDays(n,weights,mid) <= days){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;

}

int main(){
    int n=8;
    vector<int>weights={5,4,5,2,3,4,5,6};
    int days=5;

    // brute 
    brute_leastWeightCapacity(n,weights,days);

    // optimal 
    optimal_leastWeightCapacity(n,weights,days);
}