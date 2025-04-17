#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Input: N = 6, K = 3
arr[] = {2, 7, 6, 1, 4, 5}
Output: 4
Explanation: The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.

Input: N = 7, K = 3
arr[] = {-2, 2, -5, 12, -11, -1, 7}
Output: 5
Explanation: The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
*/

void brute_longSubarrWthSumDivByK(int arr[], int n, int k)
{
    // Time complexity - O(n^2)
    // space complexity - O(1)
	int result=INT_MIN;
    for(int i=0;i<n;i++){
	    long long int s=0;
	    for(int j=i;j<n;j++){
	        s+=arr[j];
	        if(s%k==0){
	            result=max(result,j-i+1);
	        }   
	    }
	}
	cout<<result<<endl;
}

void optimal_longSubarrWthSumDivByK(int arr[], int n, int k)
{
    // Time complexity - O(n)
    // space complexity - O(k)

	int result=0;
    unordered_map<int,int>mp;
    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        int remainder=currSum%k;
            
        if (remainder < 0){
            remainder += k;
        }
    
        if(remainder==0){
            result=i+1;
        }
    
        if (mp.find(remainder)==mp.end()){
            mp[remainder]=i;
        }else{
            result=max(result, i-mp[remainder]);
        } 
    }
	cout<<result<<endl;
}

int main(){
    int n=7;
    int k=3;
    int arr[n]={-2, 2, -5, 12, -11, -1, 7};


    // brute
    brute_longSubarrWthSumDivByK(arr,n,k);

    // optimal
    optimal_longSubarrWthSumDivByK(arr,n,k);

}
