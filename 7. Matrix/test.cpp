#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int n, int arr[]){
    // time complexity - O(n^2)
    // space complexity - O(1)
    
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while (j>=0 and arr[j] > temp){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void selectionSort(int n, int arr[]){
    // time complexity - O(n^2)
    // space complexity - O(1)
    int minIndex;

    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void bubbleSort(int n, int arr[]){
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        cout<<endl; 
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}


int main(){
    
    int n=5;
    int arr[n]={2,5,4,1,3};
    // insertionSort(n,arr);
    // selectionSort(n,arr);
    bubbleSort(n,arr);

}

