#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*Majority Element 

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element 
always exists in the array.

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/


int brute_majorityElement(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complecity - O(1)

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if (arr[j]==arr[i]){
                count++;
            }
        }

        if (count>n/2){
            return arr[i];
        }
    }
    return -1;
}

int better_majorityElement(int n, int arr[]){
    // Time complexity - O(n) + O(n log n)
    // space complecity - O(n)

    //declaring a map:
    map<int,int>mp;

    //storing the elements with its occurnce:
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    //searching for the majority element:
    for(auto it:mp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}

int optimal_majorityElement(int n, int arr[]){
    // Time complexity - O(n) 
    // space complecity - O(1)

    int count=0;
    int element;

    for(int i=0;i<n;i++){
        if(count==0){
            element=arr[i];
            count=1;
        }
        else if(arr[i]==element){
            count++;
        }
        else{
            count--;
        }
    }

    // verify
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            cnt++;
        }
    }

    if(cnt>n/2) return element;
    return -1;
}


int main(){
    int n=7;
    int arr[n]={2,2,3,3,1,2,2};

    // 1. brute force - 2 loop
    // cout<<brute_majorityElement(n,arr);

    // 2. better force - hashing 
    // cout<<better_majorityElement(n,arr);

    // 3. optimal force 
    cout<<optimal_majorityElement(n,arr);

    /*If the array contains a majority element, its occurrence must be greater than the floor(N/2). 
    Now, we can say that the count of minority elements and majority elements is equal up to a certain 
    point in the array. So when we traverse through the array we try to keep track of the count of elements 
    and the element itself for which we are tracking the count. 

    After traversing the whole array, we will check the element stored in the variable. 
    If the question states that the array must contain a majority element, the stored 
    element will be that one but if the question does not state so, then we need to 
    check if the stored element is the majority element or not. If not, then the array 
    does not contain any majority element.
    
    Basically, we are trying to keep track of the occurrences of the majority element and minority elements dynamically.
    The element with the most occurrence will remain and the rest will cancel themselves.
    */
}