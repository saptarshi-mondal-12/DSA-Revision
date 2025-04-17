#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Find Second Largest Element in an array

int FindsecondLargest(int n, int arr[]){
    // Time complexity - O(n logn) + O(n) 
    if(n==0 || n==1) return -1;
    
    // there can be duplicates thats why we cannot return arr[n-2] element, so we have to traverse 
    // arr=[1,2,3,4,5,5,5,5] ans=4

    sort(arr,arr+n);
    int largest=arr[n-1];
    int secondLargest;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<largest){
            secondLargest=arr[i]; 
            break;
        }
    }
    return secondLargest; 
}

int Findsecondlargest(int n, int arr[]){
    // Time complexity - O(n) + O(n) = O(2n)

    // 1. find the largest element in the array in a single traversal
    // 2. again traverse the array and find an element which is just smaller than the largest element

    if(n==0 || n==1) return -1;

    int largest=arr[0];
    for(int i=0;i<n;i++){
        if (arr[i]>largest) largest=arr[i];
    }

    int secondLargest=-1;
    for(int i=0;i<n;i++){
        if (arr[i]>secondLargest && arr[i]!=largest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;



}

int FindsecondLargestEle(int n, int arr[]){
    // Time complexity - O(n)

    if(n==0 || n==1) return -1;

    int largest=arr[0];
    int secondLargst=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            secondLargst=largest;
            largest=arr[i];
        }
        else if (arr[i] > secondLargst && arr[i]!=largest){
            secondLargst=arr[i];
        }
    }
    return secondLargst;
}

int main(){
    int n=6;
    int arr[n]={1,2,4,6,7,5};
    
    // 1. Brute force 
    // cout<<"Second largest: "<<FindsecondLargest(n,arr);

    // 2. Better  
    // cout<<"Second largest: "<<Findsecondlargest(n,arr);

    // 3. optimal soln
    cout<<"Second largest: "<<FindsecondLargestEle(n,arr);

}