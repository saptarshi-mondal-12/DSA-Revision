#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* FRUIT INTO BASKETS

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array of fruits, return the maximum number of fruits you can pick.


Input: arr[]= [2, 1, 2]
Output: 3
Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.


Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.

breakdown = max length subarray with atmost k unique elements
*/

int max_Length_With_K_Unique(vector<int>v, int k){
    // Time complexity - O(n^2)
    // space complexity - O(k+1) 

    // Intution - generate all subarray
    int n=v.size();
    int result=0;
    for(int i=0;i<n;i++){
        set<int>st;
        for(int j=i;j<n;j++){
            st.insert(v[j]);
            if (st.size() <= k){
                result=max(result, j-i+1);
            }else{
                break;
            }
        }
    }
    return result;
}

int better_max_Length_With_K_Unique(vector<int>v, int k){
    // Time complexity - O(n+n) = O(2n)
    // space complexity - O(k+1) 

    // sliding window + 2 pointer

    int n=v.size();
    int result=0;
    int left=0, right=0;
    unordered_map<int,int>mp;

    while (right < n){
        mp[v[right]]++;
        while (mp.size() > k){
            mp[v[left]]--;
            if(mp[v[left]] == 0){
                mp.erase(v[left]);
            }
            left++;
        }
        result=max(result, right-left+1);
        right++;
    }
    return result;
}


int optimal_max_Length_With_K_Unique(vector<int>v, int k){
    // Time complexity - O(n)
    // space complexity - O(k+1) 

    // sliding window + 2 pointer + removing inner while loop

    int n=v.size();
    int result=0;
    int left=0, right=0;
    unordered_map<int,int>mp;

    while (right < n){
        mp[v[right]]++;
        if (mp.size() > k){
            mp[v[left]]--;
            if(mp[v[left]] == 0){
                mp.erase(v[left]);
            }
            left++;
        }
        if (mp.size() <= k){
            result=max(result, right-left+1);
        }
        right++;
    }
    return result;
}

int main(){
    vector<int>v={3,3,3,1,2,1,1,2,3,3,4};
    int k=2;
    
    // brute
    cout<<max_Length_With_K_Unique(v,k)<<endl;

    // better
    cout<<better_max_Length_With_K_Unique(v,k)<<endl;

    // optimal
    cout<<optimal_max_Length_With_K_Unique(v,k)<<endl;


}