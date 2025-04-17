#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Minimum Time to Repair Cars

You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.
Note: All the mechanics can repair the cars simultaneously.

Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation: 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation: 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
*/



bool canRepair(vector<int>ranks, int totalCars, long long time){
    int n=ranks.size();
    long long int count=0;
    for(int i=0;i<n;i++){
        // how many car ranks[i] will able to repair under given time 
        count += sqrt(1.0 * time / ranks[i]);

        if(count >= totalCars){
            break;
        }
    }
    // If the total cars repaired is greater than required, return true
    if (count >= totalCars){
        return true;
    }
    return false;
}

long long repairCars(vector<int>& ranks, int cars) {
    // Time Complexity: O(n*log(m*max_rank))
    // Space Complexity: O(1)

    int n=ranks.size();

    // maximum possible time
    long long max_ele = *max_element(ranks.begin(), ranks.end());
    long long maxi = max_ele * cars * cars;

    // minimum possible time
    long long mini=1;

    // current result is maxi, we have to minimize it
    long long result=maxi;

    while (mini <= maxi){
        long long mid=(mini+maxi)/2;

        // function to calculate the number of cars that can be repaired in 'mid' time by all mechanics.
        if (canRepair(ranks, cars, mid)){
            result=mid;
            maxi=mid-1;

        }else{
            mini=mid+1;
        }
    }
    return result;
}

int main(){
    vector<int>ranks={4,2,3,1};
    int cars=10;
    cout<<repairCars(ranks,cars);
}