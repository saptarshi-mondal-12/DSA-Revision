#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n=asteroids.size();
    stack<int>st;
    for(int i=0;i<n;i++){
        int num=asteroids[i];

        // if asteroid is +ve just put in stack
        if(num > 0){
            st.push(num);
        }else{

            // if all where top < num just pop it
            while(!st.empty()  && st.top() < abs(num) && st.top() > 0){
                st.pop();
            }

            // if stack is empty or top()<0 then push num
            if(st.empty() || st.top() < 0){
                st.push(num);
            }

            // if top == num then remove top - both will destroy each other
            if(!st.empty() && st.top()==abs(num)){
                st.pop();
            }

        } 
    }

    // result
    vector<int>result(st.size());
    int i=st.size()-1;
    while(!st.empty()){
        result[i]=st.top();
        st.pop();
        i--;
    }
    return result;
}

int main(){
    vector<int>nums={5,10,-5};

    vector<int>result=asteroidCollision(nums);
    for(auto it: result) cout<<it<<" ";
}