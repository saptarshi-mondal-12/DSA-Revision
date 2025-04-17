#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Minimum Operations to Reduce X to Zero

You are given an integer array nums and an integer x. In one operation, you can either remove the 
leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Input: nums = [5,6,7,8,9], x = 4
Output: -1

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
*/

void minOperation(int n, int arr[], int x){
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }

    totalSum=totalSum-x;

    if(totalSum==0){
        cout<<n<<endl;
    }else{
        
        int left=0;
        int mxLen=0;
        int currSum=0;

        for(int right=0;right<n;right++){
            currSum+=arr[right];

            while (left<=right && currSum>totalSum){
                currSum-=arr[left];
                left+=1;
            }

            if(currSum==totalSum){
                mxLen=max(mxLen, right-left+1);
            }
        }
        if(mxLen!=0){
            cout<<n-mxLen<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}

int main(){
    int n=6;
    int arr[n]={3,2,20,1,1,3};
    int x=10;

    minOperation(n,arr,x);

}