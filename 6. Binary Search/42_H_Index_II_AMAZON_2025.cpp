#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. H-Index II - AMAZON 2025

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in non-descending order, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

You must write an algorithm that runs in logarithmic time.


Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Input: citations = [1,2,100]
Output: 2

Explanation:
-----------

The h-index is the largest number h such that:
    The researcher has at least h papers, and each of those papers has at least h citations.

Because the citations array is already sorted in non-decreasing (ascending) order, we can exploit this ordering to use binary search instead of scanning the array linearly.

Key Observation
Let:
    n = total number of papers
    i = current index in the sorted array

H-Index Condition:

For index i to represent a valid h-index:
    citations[i] >= (n - i)

This means:
    There are (n - i) papers
    Each of them has at least (n - i) citations
So (n - i) is a candidate h-index.

Since the array is sorted, at index i there are n - i papers with at least citations[i] citations; we binary search for the smallest i where citations[i] ≥ n - i.

*/

int hIndex(vector<int> &citations){
    // Time Complexity: O(log n) (binary search)
    // Space Complexity: O(1) (constant extra space)

    int n = citations.size();
    int left = 0, right = n - 1;
    int answer = 0;

    while (left <= right){
        int mid = (right + left) / 2;

        if (citations[mid] >= n - mid){
            answer = n - mid; // valid h-index
            right = mid - 1;  // try to find a smaller index
        }
        else{
            left = mid + 1;
        }
    }
    return answer;
}

int main(){
    vector<int> citations = {0, 1, 3, 5, 6};
    cout<<hIndex(citations);
}