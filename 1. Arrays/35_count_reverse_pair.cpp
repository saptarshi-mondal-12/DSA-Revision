#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count Reverse Pairs

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where: 
    0 <= i < j < nums.length and 
    nums[i] > 2 * nums[j].

Input: N = 5, array[] = {1,3,2,3,1)
Output: 2 
Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

Input: N = 4, array[] = {3,2,1,4}
Output: 1
Explaination: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]

*/

void brute_countPairs(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(n)

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i] > 2*arr[j]){
                count+=1;
            }
        }
    }
    cout<<count<<endl;
}

void merge(int arr[], int low, int mid, int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    int index=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[index];
        index++;
    }

}

int countPairs(int arr[], int low, int mid, int high){
    int right=mid+1;
    int count=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i] > 2*arr[right]){
            right++;
        }
        count+=(right-(mid+1));
    }
    return count;
}

int mergeSort(int arr[], int low, int high){
    int count=0;
    if (low>=high){
        return count;
    }
    int mid=(low+high)/2;
    count+=mergeSort(arr, low, mid);
    count+=mergeSort(arr,mid+1, high);
    count+=countPairs(arr,low,mid,high);
    merge(arr,low, mid, high);
    return count;
}

void optimal_countPairs(int n, int arr[]){
    // Time complexity - O(2*n log n)

    /*Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. 
    Now, inside the function countPairs(), though we are running a nested loop, we are actually 
    iterating the left half once and the right half once in total. That is why, the time complexity 
    is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. 
    Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).*/
    
    // space complexity - O(n)

    cout<<mergeSort(arr,0,n-1)<<endl;
}


int main(){
    int n=5;
    int arr[n]={1,3,2,3,1};

    // 1. brute
    brute_countPairs(n,arr);

    // 2. optimal
    optimal_countPairs(n,arr);
}