#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Encode and Decode Strings - AMAZON 2026

Given an array of strings arr[], implement an algorithm in the encode() function that can convert the given strings into a single encoded string, which can be transmitted over the network and then decoded back into the original array of strings from the encoded string. The decoding will happen in the decode() function.

The encoding rule used here is:

Each string is stored as length + "/:" + actual string.
During decoding, we first read the length before the delimiter "/:", and then extract that many characters as the original string.
This approach works for all ASCII characters since the length ensures correct parsing regardless of string content.

Note: You are not allowed to use any inbuilt serialize method.  

Examples:

Input: arr[] = ["Hello", "World"]
Output: ["Hello","World"]
Explanation: 
The encode() function converts the array into a single string by storing each word as length + "/:" + string.
For the given input, "Hello" becomes "5/:Hello", "World" becomes "5/:World". These are concatenated to form "5/:Hello5/:World", which is transmitted.

During decoding, we read the length before "/:", then extract that many characters:
Read 5 then extract "Hello"
Read 5 then extract "World"
Thus, the original array ["Hello", "World"] is reconstructed.

*/

string encode(vector<string>& arr) {
    // write your logic to encode the strings
    int n = arr.size();
    string s = "";
        
    for(int i=0;i<n;i++){
        int sz = arr[i].size();
        s += to_string(sz) + "#" + arr[i];
    }
    return s ;
}

vector<string> decode(string& s) {
    // write your logic to decode the string
    vector<string> result;
    int i = 0;
    while (i < s.size()) {
        // Find '#'
        int j = i;
        while (s[j] != '#') {
            j++;
        }
        // Get length
        int len = stoi(s.substr(i, j - i));
            
        // Move past '#'
        j++;

        // Extract string of length len
        string str = s.substr(j, len);
        result.push_back(str);
            
        // Move to next encoded string
        i = j + len;
    }
    return result;
}

int main(){

}