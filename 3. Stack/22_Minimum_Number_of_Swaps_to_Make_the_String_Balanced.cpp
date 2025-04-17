#include<iostream>
#include<stack>
using namespace std;
/* Minimum Number of Swaps to Make the String Balanced

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'. A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.Return the minimum number of swaps to make s balanced.

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.*/

    int better_minSwaps(string s) {
        // Time complexity - O(n)
        // space complexity - O(n)
        int n=s.size();
        stack<char>st;
        int unbalance=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push(s[i]);
            }else{
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }else{
                    unbalance++;
                }
            }
        }
        return (unbalance+1)/2;
    }


    int optimal_minSwaps(string s) {
        // Time complexity - O(n)
        // space complexity - O(1)
        int stackSize = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            // If character is opening bracket, increment the stack size.
            if (ch == '[')
                stackSize++;
            else {
                // If the character is closing bracket, and we have an opening
                // bracket, decrease the stack size.
                if (stackSize > 0) stackSize--;
            }
        }
        return (stackSize + 1) / 2;
    }


int main(){
    string s="]]][[[";

    // better
    cout<<better_minSwaps(s)<<endl;

    // optimal
    cout<<optimal_minSwaps(s)<<endl;
}