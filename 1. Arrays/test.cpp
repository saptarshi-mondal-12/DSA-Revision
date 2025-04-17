#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Painter’s Partition Problem

Given an array of length ‘N’, where the array represents the boards and each element of the given array represents the length of each board. 
Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. 
You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint 
that any painter will only paint the continuous sections of boards.

Input : N = 4, boards[] = {5, 5, 5, 5}, k = 2
Result: 10
Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.

Input : N = 4, boards[] = {10, 20, 30, 40}, k = 2
Result: 60
Explanation: We can divide the first 3 boards for one painter and the last board for the second painter.

Answer - min(max)
[10] [20,30,40] - 10, 90 - 90
[10,20] [30,40] - 30, 70 - 70
[10,20,30] [40] - 60, 40 - 60

ans - 60 is least 

Observations:


Minimum possible answer: 
We will get the minimum answer when we give n boards of the array to n painters(i.e. Each painter will be allocated 1 board). 
Now, in this case, the minimum time required to paint all the boards will be the maximum element in the array. 
So, the minimum possible answer is max(arr[]).

Maximum possible answer: 
We will get the maximum answer when we give all n boards to a single painter. 
The total time required is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).

From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].
*/

int countPainters(int n, vector<int>arr, int time){
    int painter=1;
    long long board=0;

    for(int i=0;i<n;i++){
        if(board+arr[i] <= time){
            board+=arr[i];
        }else{
            painter++;
            board=arr[i];
        }
    }
    return painter;

}

int brute_painter(int n, vector<int>arr, int k){
    if (n<k) return -1;

    int maxi=*max_element(arr.begin(),arr.end());
    int sum=accumulate(arr.begin(),arr.end(),0);

    for(int time=maxi;time<=sum;time++){
        if(countPainters(n,arr,time)<=k){
            return time;
        }
    }
    return -1;
}

int main(){
    int n=4;
    vector<int>arr={10,20,30,40};
    int k=2;

    cout<<brute_painter(n,arr,k)<<endl;

    
}

