#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/* Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/

vector<int> dailyTemperatures(vector<int>& temperatures) {
    // time complexity = O(n)
    // space complexity = O(n)
    // Hint: next greater
    int n=temperatures.size();
    stack<int>st;
    vector<int>result(n,0);
    for(int i=n-1;i>=0;i--){
        int curr=temperatures[i];
        while(!st.empty() && temperatures[st.top()] <= curr){
            st.pop();
        }
        if(!st.empty()){
            result[i]=st.top()-i;
        }
        st.push(i);
    }
    return result;
}

int main(){
    vector<int>temperatures={73,74,75,71,69,72,76,73}; 
    vector<int> ans= dailyTemperatures(temperatures);
    for(auto it: ans){
        cout<<it<<" ";
    }
}
