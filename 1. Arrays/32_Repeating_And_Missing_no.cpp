#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Find the repeating and missing numbers 

Input Format:  array[] = {3,1,2,5,3}
Result: {3,4)
Explanation: A = 3 , B = 4 
Since 3 is appearing twice and 4 is missing

Input Format: array[] = {3,1,2,5,4,6,7,5}
Result: {5,8)
Explanation: A = 5 , B = 8 
Since 5 is appearing twice and 8 is missing
*/

void brute_missingRepeating(int n, int arr[]){
    // Time complexity - O(N^2)
    // space complexity - O(1)

    int repeating=-1;
    int missing = -1;

    for(int i=1;i<=n;i++){
        int count=0;

        for(int j=0;j<n;j++){
            if(i==arr[j]) count++;
        }

        
        if (count==2) repeating = i;
        else if (count==0) missing=i;

        if(repeating!=-1 && missing!=-1) break;
    }

    cout<<"repeating = "<<repeating<<" "<<"Missing = "<<missing<<endl;

}


void better_missingRepeating(int n, int arr[]){
    // Time complexity - O(2N)
    // space complexity - O(N)

    // Using hashing

    int missing=-1, repeating=-1;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(mpp[i]==0){
            missing=i;
        }else if(mpp[i]==2){
            repeating = i;
        }
    }
    cout<<"repeating = "<<repeating<<" "<<"Missing = "<<missing<<endl;
}


int main(){
    int n=5;
    int arr[n]={3,1,2,5,3};

    // 1. brute 
    // brute_missingRepeating(n,arr);

    // 2. better 
    better_missingRepeating(n,arr);




}