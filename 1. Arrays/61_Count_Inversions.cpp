#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count Inversions - Amazon

Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.




Intuition----------------------------------------------------
Key Idea:
During merge sort, whenever an element from the right half is placed before an element from the left half, it forms an inversion (because the left element is greater but comes earlier in the array).

E.g. 
Input: arr[] = [2, 4, 1, 3, 5]
Goal: Count inversions — pairs (i, j) where i < j and arr[i] > arr[j].
Expected Output: Inversions: (2, 1), (4, 1), (4, 3) → Total = 3

Merge Sort Step-by-Step:
We use divide and conquer. We'll break the array, sort, and count inversions while merging.

Step 1: Initial Call
mergeSortAndCount(arr, 0, 4)

Split:
    Left: [2, 4, 1] → indices (0 to 2)
    Right: [3, 5] → indices (3 to 4)


Step 2: Sort Left Half [2, 4, 1]
Split:
    Left: [2, 4] → (0 to 1)
    Right: [1] → (2 to 2)

Left Sub-Split:
[2], [4] → merge them → No inversion (since 2 < 4)

✅ Merged: [2, 4], inv = 0

Now merge [2, 4] and [1]:
Compare 2 > 1 → inversion (2, 1)
Compare 4 > 1 → inversion (4, 1)

✅ Merged: [1, 2, 4], inv = 2

Step 3: Sort Right Half [3, 5]
[3], [5] → merge → No inversion (3 < 5)

✅ Merged: [3, 5], inv = 0

Step 4: Final Merge [1, 2, 4] and [3, 5]
    Compare 1 < 3 → no inversion
    Compare 2 < 3 → no inversion
    Compare 4 > 3 → inversion (4, 3)

✅ Merged: [1, 2, 3, 4, 5], inv = 1

Total Inversions:
From merging [2, 4] and [1]: 2
From merging [1, 2, 4] and [3, 5]: 1

Total = 2 + 1 = 3
Final Output: 3
*/

int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;     // start of left subarray
    int j = mid + 1;  // start of right subarray
    int k = left;     // start of merged array
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // Count inversions
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int x = left; x <= right; x++) arr[x] = temp[x];

    return inv_count;
}

int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int inversionCount(vector<int> &arr) {
    // Time complexity: O(n log n) 
    // Space complexity: O(n)
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
    
    
    // Brute solution ----------------------------------------------------
    // Time complexity: O(n) + O(log n) ~ O(n^2)
    // Space complexity: O(n)
    // ms.lower_bound(curr) gives an iterator to the first element not less than curr.
    // distance(ms.begin(), ms.lower_bound(curr)) counts how many elements are strictly less than curr.
    // int n = arr.size();
    // int result = 0;
    // multiset<int> ms;
    // for (int i = n - 1; i >= 0; i--) {
    //     int curr = arr[i];
    //     // Count how many elements are less than curr
    //     int lowerBoundIndex = distance(ms.begin(), ms.lower_bound(curr));
    //     result += lowerBoundIndex;
    //     ms.insert(curr);
    // }
    // return result;
}

int main(){
    vector<int>arr={2, 4, 1, 3, 5};

    cout<<inversionCount(arr)<<endl;
}