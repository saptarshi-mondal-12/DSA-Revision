#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Kth Smallest Element in a Sorted Matrix - AMAZON 2025

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Input: matrix = [[-5]], k = 1
Output: -5

TRY : HEAP FOLDER Q.12 "Kth Largest Element in an Array"



Explanation:
------------

Intuition: Binary Search on the Value Range 

We are not searching for an index in the matrix. We are searching for a value.

Because every row and every column of the matrix is sorted:
    The smallest possible answer is matrix[0][0]
    The largest possible answer is matrix[n-1][n-1]

So we binary search on the value range, not on positions.

Core Idea:

For any chosen value mid, we can efficiently compute:
    How many elements in the matrix are ≤ mid
This can be done in O(n) time by starting from the bottom-left corner and eliminating whole rows or columns at once.

Decision Logic

If count(≤ mid) < k
    → mid is too small, so the k-th smallest must be larger
    → move right: low = mid + 1

If count(≤ mid) ≥ k
    → mid could be the answer
    → keep it: high = mid

We never discard a value that could still be the k-th smallest.

Termination:
When low == high, that value is the smallest number for which at least k elements are ≤ it.
That value is the k-th smallest element.


Q. How to Count Elements ≤ mid in O(n)
Ans: Start from the bottom-left corner:

If matrix[row][col] ≤ mid
    → all elements above it in that column are also ≤ mid
    → add row + 1 to count, move right
Else
    → move up

This works because rows and columns are sorted.


Q. Why not mid-1 or mid+1?
Ans: because we are binary-searching on values with duplicates, not on indices.
Using mid - 1 or mid + 1 would break correctness.

What We Are Actually Searching For
    We are not searching for an exact position.
    We are searching for the smallest value x such that:

count( elements ≤ x ) ≥ k


That value x is exactly the k-th smallest element.
This is a classic lower_bound-style binary search.

if (count < k)
    low = mid + 1;
else
    high = mid;


Meaning of Each Case: 

Case 1: count < k
There are not enough elements ≤ mid.

➡ The k-th smallest must be strictly larger than mid

So it is safe to discard mid entirely:

low = mid + 1;

This is the only place where +1 is correct.


Case 2: count >= k
There are enough elements ≤ mid.

➡ mid could be the answer

So we must not discard mid.

That is why we do:
high = mid;
Not mid - 1.


Q. Why NOT high = mid - 1?
Ans: Because mid itself may be the k-th smallest element.

Concrete Example

Matrix elements (sorted):

[1, 5, 9, 10, 11, 12, 13, 13, 15]
k = 8

Correct answer = 13

Suppose:

mid = 13
count(≤13) = 8

If you write:

high = mid - 1;   // high = 12

You discard 13, even though:

13 is a valid answer

13 is the smallest value where count ≥ k

This would force the algorithm to return 12, which is wrong.



Q. Why Time complexiy of countLessEqual Is O(n)?
Ans: 
    row moves only upward (max n times)
    col moves only rightward (max n times)
    Total steps ≤ 2n


One-Line Summary:
Binary search the value range, and for each mid, count how many numbers are ≤ mid using the matrix’s sorted structure; the smallest value whose count reaches k is the answer.


Q. Why Not Use a Heap?
Ans: A min-heap solution takes O(n + k log n) time and O(n) space
The problem explicitly asks for better than O(n²) memory, and the binary search approach uses O(1) extra space


Why This Is Optimal
    Counting is O(n)
    Binary search is log(value range)
    Extra space is O(1)

Final Takeaway
    Use binary search on values, not indices
    Count elements ≤ mid using matrix ordering
    This is the most space-efficient and interview-preferred solution


*/


// Brute Soln -------------------------------------------------------------------------------
int brute_kthSmallest(vector<vector<int>>& matrix, int k) {
    // Time complexity: O(n^2 log(n*n))
    // Space Complexity: O(n^2)

    // Intuition: We can simply store all the elements of the matrix in a 1D array and sort it. The kth element in the sorted array will be our answer.
    vector<int> v;
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(),v.end());
    return v[k-1];
}




// Optimal Soln ------------------------------------------------------------------------------
int countLessEqual(vector<vector<int>> &matrix, int mid){
    int n = matrix.size();
    int row = n - 1, col = 0;
    int count = 0;

    while (row >= 0 && col < n){
        if (matrix[row][col] <= mid){
            count += row + 1;
            col++;
        }
        else{
            row--;
        }
    }
    return count;
}

int optimal_kthSmallest(vector<vector<int>> &matrix, int k){
    // Time complexity: O(n log(max - min)) - 
    // where max and min are the maximum and minimum elements in the matrix. In the binary search, we are reducing the search space by half in each iteration, which takes log(max - min) time. In each iteration, we are counting the number of elements less than or equal to mid, which takes O(n) time.

    // Space Complexity: O(1)


    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high){
        int mid = low + (high - low) / 2;
        int count = countLessEqual(matrix, mid);

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}



int main(){
    vector<vector<int>> matrix = {
        {1,5,9}, 
        {10,11,13}, 
        {12,13,15}};
    int k = 8;

    // brute soln
    cout << brute_kthSmallest(matrix, k)<<endl;

    // Optimal Soln
    cout << optimal_kthSmallest(matrix, k)<<endl;
}