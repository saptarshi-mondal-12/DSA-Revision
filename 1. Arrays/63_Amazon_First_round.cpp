#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Q. Number of Equivalent Domino Pairs

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3
*/

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    // Time complexity: O(n)
    // Space complexity: O(100)
    int n=dominoes.size();
    int nums[100]={0};
    int countPairs=0;
    int val=0;
    for(int i=0;i<n;i++){
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        if(a<=b){
            val=a*10+b;
        }else{
            val=b*10+a;
        }
        countPairs+=nums[val];
        nums[val]++;
    }
    return countPairs;




    // Time complexity: O(n^2)
    // Space complexity: O(1)
    // int n=dominoes.size();
    // int countPairs=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         int a = dominoes[i][0];
    //         int b = dominoes[i][1];
    //         int c = dominoes[j][0];
    //         int d = dominoes[j][1];
    //         if((a==c && b==d) || (a==d && b==c)){
    //             countPairs++;
    //         }
    //     }
    // }
    // return countPairs;
}

int main(){
    vector<vector<int>>dominoes={{1,2},{2,1},{3,4},{5,6}};
    cout<<numEquivDominoPairs(dominoes);
}