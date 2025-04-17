#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Majority Element II

Given an integer array of size n, find all elements that appear more than [ n/3 ] times.

Input: nums = [3,2,3]
Output: [3]

Input: nums = [1]
Output: [1]

Input: nums = [1,2]
Output: [1,2]*/



void brute_majority(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    /*Observation: How many integers can occur more than floor(N/3) times in the given array:
    If we closely observe, in the given array, there can be a maximum of two integers that can occur more than floor(N/3) times. 
    Assume there are 8 elements in the given array. Now, if there is any majority element, it should occur more than floor(8/3) = 2 times. 
    So, the majority of elements should occur at least 3 times. Now, if we imagine there are 3 majority elements, 
    then the total occurrence of them will be 3X3 = 9 i.e. greater than the size of the array. But this should not happen. 
    That is why there can be a maximum of 2 majority elements.*/

    vector<int>result;

    for(int i=0;i<n;i++){
        if(result.size()==0 || result[0]!=arr[i]){
            int count=0;

            for(int j=0;j<n;j++){
                if(arr[j]==arr[i]){
                    count++;
                }
            }
            if(count>n/3){
                result.push_back(arr[i]);
            }
        }

        if(result.size()==2){
            break;
        }
    }

    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
}

void better_majority(int n, int arr[]){
    // Time complexity - O(n Log n)  - Insertion in the map takes logN time. And we are doing it for N elements. 
    // space complexity - O(n)

    // Using hashing

    map<int,int>mp;
    vector<int> result;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto it:mp){
        if(it.second > n/3) result.push_back(it.first);
    }

    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
}

void optimal_majority(int n,  int arr[]){
    // Time complexity - O(n) + O(n)
    // space complexity - O(1)

    int count1=0, count2=0;
    int ele1=INT_MIN;
    int ele2=INT_MIN;

    for(int i=0;i<n;i++){
        if(count1==0 && arr[i]!=ele2){
            count1++;
            ele1=arr[i];
        }
        else if (count2==0 && arr[i]!=ele1){
            count2++;
            ele2=arr[i];
        }
        else if(arr[i]==ele1){
            count1++;
        }
        else if(arr[i]==ele2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    vector<int>result;

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    count1=0, count2=0;
    for(int i=0;i<n;i++){
        if (arr[i]==ele1) count1++;
        if (arr[i]==ele2) count2++;
    }

    if(count1 >= (n/3)+1) result.push_back(ele1);
    if(count2 >= (n/3)+1) result.push_back(ele2);


    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
}

int main(){
    int n=8;
    int arr[n]={2,1,1,3,1,4,5,6};

    // int n=3;
    // int arr[n]={1,2,3}; - output = []


    // 1. Brute 
    brute_majority(n,arr);

    // 2. Better 
    better_majority(n,arr);

    // 3. optimal 
    optimal_majority(n,arr);


}