#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Assign Cookies

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    // Time Complexity: O(n*logn + m*logm)
    // Space complexity: O(logm+logn)

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int contentChildren = 0;
    int cookieIndex = 0;
    while (cookieIndex < s.size() && contentChildren < g.size()) {
        if (s[cookieIndex] >= g[contentChildren]) {
            contentChildren++;
        }
        cookieIndex++;
    }
    return contentChildren;
}

int main(){
    vector<int>g={1,2};
    vector<int>s={1,2,3};

    cout<<findContentChildren(g,s)<<endl;
}