#include<bits/stdc++.h>
using namespace std;

/* Q. Remove extra spaces from a string - MICROSOFT 2025

Given a string containing many consecutive spaces, trim all spaces so that all words should contain only a single space between them. The conversion should be done in-place and solution should handle trailing and leading spaces and also remove preceding spaces before common punctuation like full stop, comma and a question mark.

Input: str = "   Hello Geeks  Welcome   to  GeeksforGeeks       ";
Output: "Hello Geeks Welcome to GeeksforGeeks"

Input: str = "GeeksforGeeks";
Output: "GeeksforGeeks"

*/

string removeExtraSpaces(string s){
    // Time complexity: O(n)
    // Space complexity: O(n)

    int n = s.length();
    string result = "";

    // 1. removing all leading spaces
    int i=0;
    while(i<n && s[i] == ' '){
        i++;
    }

    // 2. removing extra spaces between words and trailing spaces
    while(i<n){
        string word = "";
        int j=i;
        while(j<n && s[j] != ' '){
            word+=s[j];
            j++;
            i++;
        }
        
        // skip spaces
        while(i < n && s[i] == ' '){
            i++;
        }

        if(word.size() > 0){
            result += word + " ";
        }
    }

    if(!result.empty() && result.back() == ' '){
        result.pop_back();
    }

    return result;
}


string inPlace_removeExtraSpaces(string s){
    // Time complexity: O(n)
    // Space complexity: O(1)

    // Intuition: I use two pointers to overwrite the original string. One pointer reads characters while the other writes the cleaned output back into the same string. I skip leading spaces, copy words, allow only one space between words, and finally resize the string to remove trailing characters. This ensures O(n) time and O(1) extra space.

    int n = s.length();
    int write = 0; // index to place the next character

    // 1. removing all leading spaces
    int i=0;
    while(i<n && s[i] == ' '){
        i++;
    }

    // 2. removing extra spaces between words and trailing spaces
    while(i<n){
        // copy the word
        while(i<n && s[i] != ' '){
            s[write] = s[i];
            write++;
            i++;
        }

        // skip spaces
        while(i < n && s[i] == ' '){
            i++;
        }

        // add a single space if there are more words to process
        if(i < n){
            s[write] = ' ';
            write++;
        }
    }

    // Resize the string to the new length
    s.resize(write);

    return s;
}

int main(){
    // string str = "   Hello Geeks  Welcome   to  GeeksforGeeks       ";
    // string str = "          ";
    // string str = "          as";
    // string str = "as          ";
    string str = "  i am  s                                      ";
    // string str = "";

    // Accept solution
    string ans = removeExtraSpaces(str);
    cout<<"ans : "<<ans<<" Length = "<<ans.length()<<endl;


    // But interviewer wants in-place solution
    string ans2 = inPlace_removeExtraSpaces(str);
    cout<<"ans : "<<ans2<<" Length = "<<ans2.length()<<endl;
}