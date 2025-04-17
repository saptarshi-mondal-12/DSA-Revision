#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Sum of Middle elements of two sorted arrays

Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).

Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
*/


int brute_sum_of_middle_elements(vector<int>arr1, vector<int>arr2){
    // Time Complexity = O(2N) = (N)
    // space complexity = O(2N)= (N)

    vector<int> arr;
    int n = arr1.size();
    int i = 0, j = 0;

    // Merge the two arrays
    while (i < n && j < n) {
        if (arr1[i] <= arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
    }

    // If any elements are left in arr1
    while (i < n) {
        arr.push_back(arr1[i]);
        i++;
    }

    // If any elements are left in arr2
    while (j < n) {
        arr.push_back(arr2[j]);
        j++;
    }

    // Find the middle sum
    int middle = (n + n) / 2;
    int middleSum = arr[middle] + arr[middle - 1];

    return middleSum;
}

int optimal_sum_of_middle_elements(vector<int>arr1, vector<int>arr2){
    // Time complexity - O(n) + O(n log n) + O(n log n)
    // space complexity - O(1)

    int n = arr1.size();
    int i = n - 1;
    int j = 0;

    // Swap elements from the end of arr1 and the beginning of arr2
    while (i >= 0 && j < n) {
        if (arr2[j] < arr1[i]) {
            // Swap arr2[j] and arr1[i]
            swap(arr2[j], arr1[i]);
            i--;
            j++;
        } else {
            break;
        }
    }

    // Sort both arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // Calculate the sum of the largest element in arr1 and the smallest in arr2
    int middleSum = arr1[n - 1] + arr2[0];

    return middleSum;
}


int main(){
    vector<int>arr1={1, 2, 4, 6, 10};
    vector<int>arr2={4, 5, 6, 9, 12};

    cout<<brute_sum_of_middle_elements(arr1,arr2)<<endl;
    cout<<optimal_sum_of_middle_elements(arr1,arr2)<<endl;
}




