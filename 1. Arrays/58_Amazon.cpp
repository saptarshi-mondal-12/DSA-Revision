#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Given an array of numbers and a value k. You need to find the maximum count of k the array can have. You can do 1 operation in which you can pick any subarray of the given array and add a number to all the elements in the subarray.

Initial Array: [1, 2, 3, 4, 5]
Target Value k: 5
ans : 2

Initial Array: [5, 4, 3, 4, 5]
Target Value k: 5
ans : 4


Intuition: ----------------------------
Hint: Try to find the subarray (or elements) with the maximum frequency, excluding the target value k. This is because if we convert the most frequent number (other than k) to k by adding a value +x, we can maximize the number of times k appears in the array.

Example 1:
Initial Array: [1, 2, 3, 4, 5]
Target Value k: 5

Frequencies= [1:1, 2:1, 3:1, 4:1, 5:1]
Ans: 2
Expalanation : Every element occurs only once, including 5. So we can pick any one element other than 5 (e.g., 4), and add +1 to make it 5.
New array after modification: [1, 2, 3, 5, 5]
Now, the number 5 appears twice, so the answer is 2.


Example 2:
Initial Array: [5, 4, 3, 4, 5]
Target Value k: 5

Frequencies= [3:1, 4:2, 5: 2]
Ans: 4 
Expalanation : We ignore the count of 5 (target value). The most frequent number apart from 5 is 4 (frequency = 2).
If we convert all 4s to 5 by adding +1, we get:
[5, 5, 3, 5, 5]
Now, the number 5 appears 4 times, so the answer is 4.  
*/

int maxKCountAfterAddition(vector<int>nums, int k) {
    // Time complexity: O(n^2)
    // Space complexity: O(n)

    int n = nums.size();
    int totalK = 0;
    
    // Count how many k's are already present
    for (int num : nums) {
        if (num == k) totalK++;
    }

    int result = totalK;

    // For every possible subarray
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> freq;
        int countK = 0;

        for (int j = i; j < n; j++) {
            if (nums[j] == k) {
                countK++;
            } else {
                int x = k - nums[j];
                freq[x]++;
                result = max(result, totalK + freq[x] - countK);
            }
        }
    }
    return result;
}

int main() {
    // Example 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 5;
    cout << "Output: " << maxKCountAfterAddition(arr1, k1) << endl; // Output: 2

    // Example 2
    vector<int> arr2 = {5, 4, 3, 4, 5};
    int k2 = 5;
    cout << "Output: " << maxKCountAfterAddition(arr2, k2) << endl; // Output: 4


    // Example 3
    vector<int> arr3 = {4,4,4,5,4,4,4};
    int k3 = 5;
    cout << "Output: " << maxKCountAfterAddition(arr3, k3) << endl; // Output: 6

    // Example 4
    vector<int> arr4 = {1,1,5,1,1};
    int k4 = 5;
    cout << "Output: " << maxKCountAfterAddition(arr4, k4) << endl; // Output: 4

    // Example 5
    vector<int> arr5 = {1,5,5,5,1,1};
    int k5 = 5;
    cout << "Output: " << maxKCountAfterAddition(arr5, k5) << endl; // Output: 5

    // Example 6:
    vector<int> arr6 = {2,5,5,5,2,1,1,1,1,1,1};
    int k6 = 5;
    cout << "Output: " << maxKCountAfterAddition(arr6, k6) << endl; // Output: 9 consider this subarray = [1,1,1,1,1,1] -> 6+3=9
    

    return 0;
}
