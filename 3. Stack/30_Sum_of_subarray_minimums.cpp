#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Input: arr = [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17.

Input: arr = [11,81,94,43,3]
Output: 444


Explanation:
------------

[3, 1, 2, 4]

3 = 3
3,1 = 1
3,1,2 = 1
3,1,2,4 = 1

1 = 1
1,2 = 1
1,2,4 = 1

2 = 2
2,4 = 2

4 = 4

Total = 3+1+1+1+1+1+1+2+2+4 = 17 (ans)


Q. How many time each element contribute to out answer ?
Ans:    x1 x6 x2 x1
        [3, 1, 2, 4]

        3*1 + 1*6 + 2*2 + 4*1 = 3+6+4+4 = 17 


Q. But how do we find how many time does each element contributes to answer ?
Ans: 
    [1, 4, 6, 7, 3, 7, 8, 1]

    Let's calculate for 3 -------> finding how many 3 contribute to our answer
    
    On Right side: 3
                 |-----|
    [1, 4, 6, 7, 3, 7, 8, 1]


     On Left side: 4
        |--------|
    [1, 4, 6, 7, 3, 7, 8, 1]


Q. But how we caluculate 3 on right side and 4 on left side ?
Ans: Using next smaller element and previous smaller element. 

    for 3: 3 is at 4th index
            next smaller element is 1 and its index is = 7th
            previous smaller element of 1 and its index is = 0th

    So, 
        7-4 = 3
        4-0 = 4

    Total = 4 x 3 = 12 Time its contrubute measn 12 x 3 = 36 is added to our answer. 

    [4,6,7,3], [4,6,7,3,7], [4,6,7,3,7,8]
    [6,7,3], [6,7,3,7], [6,7,3,7,8]
    [7,3], [7,3,7], [7,3,7,8]
    [3], [3,7], [3,7,8]

    Total = 12 subarray where 3 is minimum . so 12 x 3 = 36 is added to answer

Optimal Solution:
        1. Find next smaller element index 
                    |
                    --> if no next smaller put n

        2. Find previous smaller or equal index
                    |
            put 0 <--

        3. Calculate for each element

        NOTE: STORE INDEX ONLY 

        total += (left * right * arr[i])


*/

vector<int>prev_smaller_element(vector<int>& arr){
    // Time complexity - O(2n)
    // space complexity -  O(n) + O(n) = O(2n)
    int n=arr.size();
    vector<int>pse(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i] < arr[st.top()] ){
            st.pop();
        }
        if(st.empty()){
            pse[i]=-1;
        }else{
            pse[i]=st.top();
        }
        st.push(i);
    }
    return pse;
}
vector<int>next_smaller_element(vector<int>& arr){
    // Time complexity - O(2n)
    // space complexity -  O(n) + O(n) = O(2n)
    // 1 4 6 7 3 7 8 1
    int n=arr.size();
    vector<int>nse(n,0);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        // pop till arr[i] <= arr[st.top()]because we want next smaller
        while (!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }
        // if stack become empty assign to n because whole element can be considered after current index 
        if(st.empty()){
            nse[i]=n;
        }else{
            nse[i]=st.top();
        }
    
        // Push index not array element because we need index
        st.push(i);
    }
    return nse;
}
    
int sumSubarrayMins(vector<int>& arr) {
    // Time complexity - O(2n) + O(2n) + O(n) = O(5n)
    // space complexity - O(2n + 2n + n) = O(5n) = O(n)
    
    int n=arr.size();
    int result=0;
    int mod=(1e9)+7;
            
    vector<int>prevSmallerElement = prev_smaller_element(arr);
    vector<int>nextSmallerElement = next_smaller_element(arr);
    
    for(int i=0;i<n;i++){
        int left = i - prevSmallerElement[i];
        int right = nextSmallerElement[i] - i;
        result = (result + (left * right * 1LL * arr[i])) % mod;
    }
    return result;
}


// Brute soln - Generating all subarray, finding minimum in each subarray, and adding to answer
int brute_sumSubarrayMins(vector<int>& arr) {
    // Time complexity - O(N^2)
    // space complexity - O(1)
    int n=arr.size();
    long long int MOD = 1000000007;
    long long int result=0;
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            mini=min(mini, arr[j]);
            result+=mini;
        }
    }
    return result % MOD;  
}
    

int main(){
    vector<int>arr={1, 4, 6, 7, 3, 7, 8, 1};

    // brute
    // cout<<brute_sumSubarrayMins(arr);

    // optimal
    cout<<sumSubarrayMins(arr);


}