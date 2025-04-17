#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// check if array is sorted or not

bool brute_isSorted(int arr[], int n) {
    // Time complexity - O(n^2)

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[i])
            return false;
        }
    }
    return true;
}

bool optimal_isSorted(int arr[], int n) {
    // Time complexity - O(n)

    // sorted means = increasing order [2<3<4<5<6]
    
    for (int i = 1; i < n; i++) {
        if (arr[i-1] > arr[i])
            return false;
    }
    return true;
}

int main() {
    int n=5;
    int arr[] = {1, 2, 3, 4, 5};

    // 1. Brute force 
    // printf("%s", brute_isSorted(arr, n) ? "True" : "False");

    // 2. optimal force 
    printf("%s", optimal_isSorted(arr, n) ? "True" : "False");

}