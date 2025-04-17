#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  Best Time to Buy and Sell Stock


You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

void brute_maxProfit(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int maxProfit=0;
    for(int buy=0;buy<n;buy++){
        for(int sell=buy+1;sell<n;sell++){
            if (arr[sell]>arr[buy]){
                maxProfit=max(maxProfit,arr[sell]-arr[buy]);
            }
        }
    }
    cout<< maxProfit<<endl;

    

}

void optimal_maxProfit(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    int maxprofit=0;
    int minPrice=arr[0];

    for(int i=1;i<n;i++){
        if (arr[i] < minPrice){
            minPrice=arr[i];
        }
        maxprofit=max(maxprofit,arr[i]-minPrice);
    }
    cout<<maxprofit;

}

int main(){
    int n=6;
    int arr[n]={7,1,5,3,6,4};
    
    // 1. Brute
    brute_maxProfit(n,arr);

    // 2. optimal
    optimal_maxProfit(n,arr);
}