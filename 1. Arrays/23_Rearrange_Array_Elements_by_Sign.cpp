#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  Rearrange Array Elements by Sign

There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of 
positive and negative elements, you must return an array of alternately positive and negative values.

Note: Start the array with positive elements.
 
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation: The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].The only possible way to rearrange 
them such that they satisfy all conditions is [3,-2,1,-5,2,-4].

Input: nums = [-1,1]
Output: [1,-1]
*/

vector<int> brute_rearrangeArray(int n, int arr[]){
    // Time complexity - O(n + n/2) = O(n)
    // space complexity - O(n/2) + O(n/2) = O(n)

    vector<int>positive;
    vector<int>negative;

    for(int i=0;i<n;i++){
        if(arr[i]<0) negative.push_back(arr[i]);
        else positive.push_back(arr[i]);
    }

    for(int i=0;i<n/2;i++){
        arr[2*i] = positive[i];
        arr[2*i+1] = negative[i];
    }vector<int>(arr, arr + n); 

    return vector<int> (arr,arr+n);
}

vector<int> optimal_rearrangeArray(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(n)

    vector<int> result(n,0);

    int positiveIndex=0;
    int negativeIndex=1;

    for(int i=0;i<n;i++){
        if (arr[i]<0){
            result[negativeIndex]=arr[i];
            negativeIndex+=2;

        }else{
            result[positiveIndex]=arr[i];
            positiveIndex+=2;
        }
    }
    return result;
}

vector<int> variety_1(int n, int arr[]){
    // Time complexity - O(n) + O(n) = (2n)
    // space complexity - O(n)

    vector<int>positive;
    vector<int>negative;

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            negative.push_back(arr[i]);
        }
        else{
            positive.push_back(arr[i]);
        }
    }

    int mini=min(positive.size(),negative.size());

    
    for(int i=0;i<mini;i++){
        arr[2*i]=positive[i];
        arr[2*i+1]=negative[i];
    }

    int i=mini;
    int index=i*2;

    // remaining positive element
    while(i<positive.size()){
        arr[index]=positive[i];
        i+=1;
        index+=1;
    }
    // remaining negative element
    while(i<negative.size()){
        arr[index]=negative[i];
        i+=1;
        index+=1;
    }
    return vector<int>(arr,arr+n);
}

int main(){
    int n=9;
    int arr[n]={3,1,-2,-5,2,-4,7,8,9};

    // 1. Brute
    // vector<int>result=brute_rearrangeArray(n,arr);

    // 2. optimal
    // vector<int>result=optimal_rearrangeArray(n,arr);

    // follow up ques - if no of positive != no of negative

    vector<int>result=variety_1(n,arr);

    for(int i=0;i<n;i++) cout<<result[i]<<" ";


    



}