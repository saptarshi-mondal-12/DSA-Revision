#include<bits/stdc++.h>
using namespace std;


/* Q. Count Good Meals - AMAZON 2026

A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.

You can pick any two different foods to make a good meal.

Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.

Note that items with different indices are considered different even if they have the same deliciousness value.

 

Example 1:

Input: deliciousness = [1,3,5,7,9]
Output: 4
Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
Example 2:

Input: deliciousness = [1,1,1,3,3,3,7]
Output: 15
Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.

Intuition ----------------------------------------------------------------------------------------------

Intuition:

We need to count pairs (i, j) such that:

delicious[i] + delicious[j] = power of 2

A brute-force approach would check every pair, which takes O(n^2).

The key observation is that the sum can only be a power of 2. Since the values in the array are limited, there are only a small number of possible powers of 2 that can be a valid sum.

So, for every number x, we try every possible power of 2.

If the target sum is power, then the number we need is:

need = power - x

We maintain a frequency map of numbers that we have already seen.

For example, if the current number is 5:

For power = 8, we need 3 because 3 + 5 = 8.

For power = 16, we need 11 because 11 + 5 = 16.

For power = 32, we need 27 because 27 + 5 = 32.

If 3 has already appeared in the array, then we have found a valid pair (3, 5).

The frequency map also handles duplicates. If 3 appeared 4 times before 5, then there are 4 valid pairs with the current 5.

Algorithm:

Create a frequency map to store numbers seen so far.

Create a list of all relevant powers of 2.

For every number x:

For every power of 2:

Calculate need = power - x.

Add the frequency of need to the answer.

Add x to the frequency map.

Return the answer modulo 1e9 + 7.

Complexity:

There are only about 22 powers of 2 to check for each element.

Time: O(22 * n), which is effectively O(n).
Space: O(n) for the frequency map.

The main idea is: Instead of checking every pair, for each number we check only the small set of possible powers of 2 and find the required partner using a frequency map.
*/

class Solution {
public:
    bool checkPowerOfTwo(int n){
        if(n > 0 && (n & (n-1)) == 0){
            return true;
        }
        return false;
    }
    int countPairs(vector<int>& delicious) {
        const int MOD = 1e9 + 7;

        unordered_map<int, long long> mp;
        long long result = 0;

        vector<int> powerOfTwo;

        for (int i = 0; i <= 21; i++) {
            powerOfTwo.push_back(pow(2,i));
        }

        for (int x : delicious) {
            for (int power : powerOfTwo) {
                int need = power - x;

                if (mp.find(need) != mp.end()) {
                    result += mp[need];
                }
            }

            mp[x]++;
        }

        return result % MOD;




        // Time complexity: O(n^2)
        // Sapce complexity: O(1)
        // int n = delicious.size();
        // int result = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int a = delicious[i];
        //         int b = delicious[j];
        //         if(checkPowerOfTwo(a+b)){
        //             result++;
        //         }
        //     }
        // }
        // return result;
    }
};