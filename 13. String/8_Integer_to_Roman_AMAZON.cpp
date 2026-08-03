#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Integer to Roman - AMAZON 2026

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.



Input: num = 3749
Output: "MMMDCCXLIX"
Explanation:
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
700 = DCC as 500 (D) + 100 (C) + 100 (C)
40 = XL as 10 (X) less of 50 (L)
9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

Input: num = 58
Output: "LVIII"
Explanation:
50 = L
8 = VIII

Input: num = 1994
Output: "MCMXCIV"
Explanation:
1000 = M
900 = CM
90 = XC
4 = IV
*/

string intToRoman(int num) {
    // Time complexity: O(1) (because the vector size is fixed)
    // Space complexity: O(1) (fixed storage)

    /* 
    I am storing the Roman numeral rules in a vector of pairs. Each pair contains a decimal value and its corresponding Roman symbol. I keep the values in descending order so that I can greedily pick the largest possible Roman value first.

    Q. Why descending order?
    Ans: Because Roman conversion works by taking the biggest value possible first.
        Example: 3749

        We check from the top:
        1000 → M

        Since 3749 is greater than 1000:
        3749 - 1000 = 2749
        answer = M

        Again:
        2749 - 1000 = 1749
        answer = MM

        Again:

        1749 - 1000 = 749
        answer = MMM

        Now 1000 is not possible, so we move down:
        500 → D
        and continue.


    Q. Why do we include 900, 400, 90, 40, 9, 4?
    Ans: These are special subtractive cases.
        Instead of:
        900 = DCCCC ❌
        Roman rules use:
        900 = CM ✅
        Similarly:
        40 = XL
        9  = IX
        4  = IV
        If we don't store these separately, our algorithm would produce invalid Roman numerals.


    Q. Why vector of pairs instead of unordered_map?
    Ans: I used a vector because the order matters. A map/unordered_map does not guarantee the descending order needed for the greedy approach. Since I need to always try the largest value first, vector is the better choice.
        
    */
    vector<pair<int, string>> mp = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    string ans = "";

    for (auto &it : mp) {
        while (num >= it.first) {
            ans += it.second;
            num -= it.first;
        }
    }

    return ans;
}

int main(){
    int n = 2025;
    cout<<intToRoman(n);
}