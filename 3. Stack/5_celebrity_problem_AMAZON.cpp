#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/* The Celebrity Problem 

A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Input: mat[][] = [[1, 1, 0],
                [0, 1, 0],
                [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.


Input: mat[][] = [[1, 1], 
                [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.


Input: mat[][] = [[1]]
Output: 0


    0 0 1 0
    0 0 1 0
    0 0 0 0
    0 0 1 0

    ans = 3, because 2-0 ko nhi janta, 2-1, 2-2(avoiding diagonal), 2-3 ko nhi janta

    brute force -
    celebrity - row - all 0's (kisi ko nhi janta)
    celebrity - col - all 1's (except diagonal element) (celebrity ko sb jante hai)

*/

bool knows(vector<vector<int>>&arr, int a, int b){
    if (arr[a][b]==1) return true;
    return false;
}

int better_celebrity(vector<vector<int>>&arr, int n ){
    // time complexity O(n)
    // space complexity O(n)

    // 1. PUSH all person to stack i.e n=5, 0,1,2,3,4
    stack<int>s;
    for (int i=0;i<n;i++){
        s.push(i);
    }


    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();

        // if a - b ko janta hai toh a celebrity nhi hoga
        if (knows(arr,a,b)){
            s.push(b);

        }else{
            s.push(a);

        }
    }

    // potential candidate
    int celebrity=s.top();

    // 2. verify the potential candidate

    // checking that celebrity knows no one i.e all 0's
    int countZero=0;
    for(int i=0;i<n;i++){
        if(arr[celebrity][i]==0){
            countZero++;
        }
    }
    if (countZero!=n){
        return -1;
    }

    // checking everyone knows celebrity i.e all 1 i.e TOTAL 1'S = n-1
    int countOne=0;
    for(int i=0;i<n;i++){
        if(arr[i][celebrity]==1){
            countOne++;
        }
    }
    if (countOne!=n-1){
        return -1;
    }
    
    return celebrity;
}


int optimal_celebrity(vector<vector<int>>&arr, int n){
    // time complexity O(n)
    // space complexity O(1)

    int a=0;
    int b=n-1;

    while(a<b){
        // if a - b ko janta hai toh a celebrity nhi hoga islye a++
        if (arr[a][b]==1){
            a++;
        }else{
            b--;
        }
    }
    int celebrity=a;

    // 1. checking that celebrity knows no one
    int countZero=0;
    for(int i=0;i<n;i++){
        if(arr[celebrity][i]==0){
            countZero++;
        }
    }
    if (countZero!=n){
        return -1;
    }

    // 2. checking everyone knows celebrity
    int countOne=0;
    for(int i=0;i<n;i++){
        if(arr[i][celebrity]==1){
            countOne++;
        }
    }
    if (countOne!=n-1){
        return -1;
    }
    return celebrity;
}

int main(){
    int n=3;
    vector<vector<int>>arr={{0,1,0},{0,0,0},{0,1,0}};
    

    // better 
    cout<<better_celebrity(arr,n)<<endl;

    // optimal
    cout<<optimal_celebrity(arr,n)<<endl;
    
}