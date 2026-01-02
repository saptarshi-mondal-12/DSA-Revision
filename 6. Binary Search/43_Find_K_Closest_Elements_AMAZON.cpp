#include <bits/stdc++.h>
using namespace std;

/* Q. Find K Closest Elements - AMAZON 2025

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]

NOTE: Q. WHY LEFT+1 AND RIGHT-1 INSTEAD OF LEFT AND RIGHT?
ANS: DRY RUN ON 1ST EXAMPLE TO UNDERSTAND THIS.
*/

// Brtue soln ---------------------------------------------------------------
vector<int> brute_findClosestElements(vector<int> &nums, int k, int x){
    // Time complexity: O(nlogk) + O(klogk)
    // Space complexity: O(k)

    // Intution: We can use a max heap to keep track of the k closest elements to x. If the size of the heap exceeds k, we remove the element with the largest difference from x. And at last our heap will contain the k closest elements to x.

    int n = nums.size();
    vector<int> result;

    // Edge cases: if x is less than or equal to the first element, we can directly return the first k elements
    if (x <= nums[0]){
        for (int i = 0; i < k; i++){
            result.push_back(nums[i]);
        }
        return result;
    }

    // Edge cases: if x is greater than or equal to the last element, we can directly return the last k elements
    if (x >= nums[n - 1]){
        for (int i = n - k; i < n; i++){
            result.push_back(nums[i]);
        }
        return result;
    }

    // Implementing max heap using priority queue
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++){
        int num = nums[i];
        int diff = abs(num - x);
        pq.push({diff, num});
        if (pq.size() > k){
            pq.pop();
        }
    }

    while (!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }

    // Sorting the result before returning
    sort(result.begin(), result.end());
    return result;
}



// Optimal soln ---------------------------------------------------------------
vector<int> optimal_findClosestElements(vector<int> &nums, int k, int x){
    // Time complexity: O(logn + k)
    // Space complexity: O(1)

    int n = nums.size();
    vector<int>result;

    // Intuition: Since the array is sorted, so first we try to 
    // 1. find the correct position of x using binary search.    
    // 2. Second we use two pointers to find the k closest elements to x.
    // 3. we finally get the range of k closest elements, so we push them into the result vector.


    // 1. find the correct position of x
    int low = 0, high = n-1;
    while(low<high){
        int mid = (low+high)/2;
        if (nums[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }


    // 2. use two pointers to find the k closest elements to x
    // Now low is the index of the smallest number greater than or equal to x
    int right = low;
    int left = low - 1;
    while(k--){
        if (left < 0){
            right++;
        }
        else if (right >= n){
            left--;
        }
        else{
            if (abs(nums[left] - x) <= abs(nums[right] - x)){
                left--;
            }
            else{
                right++;
            }
        }
    }

    // Now the k closest elements are in the range [left + 1, right - 1]
    for (int i = left + 1; i < right; i++){
        result.push_back(nums[i]);
    }

    return result;

}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    // 1. Brute solution 
    // vector<int> result = brute_findClosestElements(arr, k, x);


    // 2. Optimal solution
    vector<int> result = optimal_findClosestElements(arr, k, x);


    for (int num : result){
        cout << num << " ";
    }
    cout << endl;

}