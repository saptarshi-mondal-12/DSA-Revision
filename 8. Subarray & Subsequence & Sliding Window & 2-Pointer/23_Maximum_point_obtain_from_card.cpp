#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Maximum point you can obtain from card

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

Explanation - 
int n=9;
int arr[n]={6,2,3,4,7,2,1,7,1};
int k=4;
output: 16

6+2+3+4=15
6+2+3+1=12
6+2+1+7=16
6+1+7+1=15
2+1+7+1=11
*/

int maximumPoint(int n, int arr[], int k){
    // Time complexity - O(2*K)
    // space complexity - O(1)
    int result=0;
    int leftSum=0, rightSum=0;

    for(int i=0;i<k;i++){
        leftSum+=arr[i];
    }
    result=max(result,leftSum);
    int rightIndex=n-1;
    for(int i=k-1; i>=0;i--){
        leftSum-=arr[i];
        rightSum=rightSum+arr[rightIndex];
        int total=leftSum+rightSum;
        rightIndex--;
        result=max(result, total);
    }
    return result;

}

int main(){
    int n=9;
    int arr[n]={6,2,3,4,7,2,1,7,1};
    int k=4;
    cout<<maximumPoint(n,arr,k);
}