#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int n,int arr[]){
    /* 
    Best case : O(n)
    Average case : O(n^2)
    worst case   : O(n^2)
    */

    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=arr[i];
        while(j>=0 and arr[j] > temp){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=temp; 
    }
}

void selectionSort(int n,int arr[]){
    /*
    Best case : O(n^2)
    Average case : O(n^2)
    worst case   : O(n^2)
    */
    for(int i=0;i<n;i++){
        int minIndex=i;

        // finding minimum element
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        // swapping
        swap(arr[minIndex],arr[i]);
    }
}

void bubbleSort(int n, int arr[]){

    /* it pushes maximum element to last using adjacent swapping
    Best case : O(n) (all element are sorted)
    Average case : O(n^2)
    worst case   : O(n^2)
    */

    // total no of rount = 1 to n-1
    for(int i=1;i<n;i++){
        // compare adjacent element arr[j] > arr[j+1]
        int didSwap=0;
        for(int j=0;j<n-i;j++){
            if (arr[j]>arr[j+1]){
                // swapping
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
        }
        if (didSwap==0) break;
    }
}

void merge(int arr[], int low, int mid, int high){
    // temporary array
    vector<int> temp;

    // starting index of left half of arr
    int left=low;

    // starting index of right half of arr
    int right=mid+1;

    //storing elements in the temporary array in a sorted manner

    while (left<=mid && right<=high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }   

    // if element of left half is still left
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    // if element of right half is still left
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    // transferring all element from temporary to arr
    int indx=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[indx];
        indx++;
    }

}

void mergeSort(int arr[],int low,int high){

    // time complexity - O(n logn ) At each step, we divide the whole array, for that log n 
    // and we assume n steps are taken to get sorted array, so overall time complexity will be nlog n

    // space complexity -  O(N)

    // 1. Merge Sort is a divide and conquers algorithm, it divides the given array into equal parts and then merges the 2 sorted parts. 
    
    // 2. There are 2 main functions :
    //     merge(): This function is used to merge the 2 halves of the array. It assumes that both parts of the array are sorted and merges both of them.
    //     mergeSort(): This function divides the array into 2 parts. low to mid and mid+1 to high where,
    
    // 3. We recursively split the array, and go from top-down until all sub-arrays size becomes 1.
    
    if (low>=high) return;
    int mid=(low+high)/2;

    // left half
    mergeSort(arr,low,mid);

    // right half
    mergeSort(arr,mid+1,high);

    // mergeing sorted halfves
    merge(arr,low,mid,high);
}


int partition(int arr[], int low, int high){

    // 1. choose pivot element
    int pivot=arr[low];

    // 2. count no of element less than pivot
    int count=0;
    for(int i=low+1;i<=high;i++)
        if(arr[i]<=pivot) count++;

    // 3. place pivot at right position 
    int pivotIndex=low+count;
    swap(arr[pivotIndex],arr[low]);

    // element less that pivot should be in left side
    // greater element are on right side of pivot element ... < pivot > ...
    int i=low;
    int j=high;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int low, int high){
    // Time complexity - O(n log n)
    // space complexity - O(1) + O(N) auxiliary stack space.

    if(low>=high) return ;

    int pivot=partition(arr,low,high);

    // sort left part
    quickSort(arr,low,pivot-1);

    // sort right part
    quickSort(arr,pivot+1,high);

    // Q. why quick sort is preferred over merge sort for sorting arrays.
    // Q. why merge sort is preferred over quick sort for linkedList
}



int main(){
    int n=7;
    int arr[n]={10,1,6,2,8,5,11};

    // 1. insertion sort
    insertionSort(n,arr);

    // 2. selection sort
    // selectionSort(n,arr);

    // 3. Bubble sort
    // bubbleSort(n,arr);

    // 4. Merge sort
    // mergeSort(arr,0,n-1);
    
    // 5. quick sort 
    // quickSort(arr,0,n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}