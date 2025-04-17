#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Longest Consecutive Sequence in an Array
You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Input: [100, 200, 1, 3, 2, 4]
Output: 4
Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

Input: [3, 8, 5, 7, 6]
Output: 4
Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
*/

bool linearSearch(int n, int arr[], int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}

void brute_longestConsecutive(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(1)
    int longest=1;
    for(int i=0;i<n;i++){
        int x=arr[i];
        int count=1;
        while(linearSearch(n,arr,x+1)==true){
            x=x+1;
            count+=1;
        }
        longest=max(longest,count);
    }
    cout<<longest<<endl;
}

void better_longestConsecutive(int n, int arr[]){
    // Time complexity - O(n log n) + O(n)
    // space complexity - O(1)

    sort(arr,arr+n); // 1 2 3 4 100 200

    int count=0;
    int lastSmaller=INT_MIN;
    // as the minimum length of the sequence is 1 
    int longest=0;

    for(int i=0;i<n;i++){

        if(arr[i]-1==lastSmaller){
            count+=1;
            lastSmaller=arr[i];
        }
        else if (arr[i]!=lastSmaller){
            count=1;
            lastSmaller=arr[i];
        }
        longest=max(longest,count);

    }
    cout<<longest<<endl;
}

void optimal_longestConsecutive(int n, int arr[]){
    // Time complexity - O(n) + O(2n) ~ O(3n)
    // space complexity - O(n)

    int longest=1;
    unordered_set<int>s; // 102,4,100,1,101,3,2
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    for(auto it:s){
        // if x-1 not on set
        if(s.find(it-1)==s.end()){
            int count=1;
            // the x is the 1st element
            int x=it;
            while(s.find(x+1)!=s.end()){
                x=x+1;
                count=count+1;
            }
            longest=max(longest,count);
        }
    }
    cout<<longest<<endl;
}

int main(){
    int n=9;
    int arr[n]={102,4,100,1,101,3,2,1,1};

    // 1. brute
    // brute_longestConsecutive(n,arr);

    // 2. better
    // better_longestConsecutive(n,arr);

    // 3. optimal
    optimal_longestConsecutive(n,arr);


}