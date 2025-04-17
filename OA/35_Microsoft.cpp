#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/* Q. 
The uniqueness of an array of integers is defined as the number of distinct elements present.
For example, the uniqueness of [1, 5, 2, 1, 3, 5] is 4, element values 1, 2, 3, and 5.

For an array arr of n integers, the uniqueness values of its subarrays is generated and stored in another array, call it subarray_uniqueness for discussion. Find the median of the generated array subarray_uniqueness.

Notes :-
1. The median of a list is defined as the middle value of the list when it is sorted in non-decreasing order. If there are multiple choices for median, the smaller of the two values is taken.
For example, the median of [1, 5, 8] is 5, and of [2, 3, 7, 11] is 3.

2. A subarray is a contiguous part of the array. For example, [1, 2, 3] is a subarray of [6, 1, 2, 3,
5] but [6, 2] is not.

Example 1:
There are n = 3 elements in arr = [1, 2, 1]. The subarrays along with their uniqueness values are:
[1]: uniqueness = 1
[1, 2] : uniqueness = 2
[1,2, 1]: uniqueness = 2
[2] : uniqueness = 1
[2, 1]: uniqueness = 2
[1] : uniqueness = 1

The subarray_uniqueness array is [1, 2, 2, 1, 2, 1]. After sorting, the array is [1, 1, 1, 2, 2, 2].
The choice is between the two bold values. Return the minimum of the two,1. Output : 1

Example 2 :
arr = [1, 2, 3]
[1]: uniqueness = 1
[1, 2] : uniqueness = 2
[1,2, 3]: uniqueness = 3
[2] : uniqueness = 1
[2, 3]: uniqueness = 2
[3] : uniqueness = 1

After sorting, the array is [1, 1, 1, 2, 2, 3]. Output : 1.*/

int medianSubarrayUniqueness(const vector<int>& arr) {
    int n = arr.size();
    vector<int> subarray_uniqueness;

    for (int i = 0; i < n; ++i) {
        unordered_set<int> seen;
        for (int j = i; j < n; ++j) {
            seen.insert(arr[j]);
            subarray_uniqueness.push_back(seen.size());
        }
    }

    sort(subarray_uniqueness.begin(), subarray_uniqueness.end());
    int m = subarray_uniqueness.size();

    // If even number of elements, return the smaller of the two middle values
    if (m % 2 == 0) {
        return subarray_uniqueness[(m / 2) - 1];
    } else {
        return subarray_uniqueness[m / 2];
    }
}
int main() {
    vector<int> arr1 = {1, 2, 1};
    cout << "Median: " << medianSubarrayUniqueness(arr1) << endl; // Output: 1

    vector<int> arr2 = {1, 2, 3};
    cout << "Median: " << medianSubarrayUniqueness(arr2) << endl; // Output: 1

    vector<int> arr3 = {1, 5, 2, 1, 3, 5};
    cout << "Median: " << medianSubarrayUniqueness(arr3) << endl;

    return 0;
}
