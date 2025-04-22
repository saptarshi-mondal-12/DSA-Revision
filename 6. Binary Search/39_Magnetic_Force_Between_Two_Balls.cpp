#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Magnetic Force Between Two Balls

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
*/

bool isPossible(vector<int>& position, int m, int mid){
    int n=position.size();
    int ball=1;
    // Place the first ball at the first position.
    int last=position[0];
    for(int i=1;i<n;i++){
        // Check if we can place the ball at the current position.
        if(position[i] - last >= mid){
            ball+=1;
            last=position[i];
        }
    }
    // If all 'm' balls are placed, return 'true'.
    if(ball >= m){
        return true;
    }
    return false;
}
int maxDistance(vector<int>& position, int m) {
    // Time complexity: O(n log n) + O(nlogn)
    // space complexity: O(1)

    int n=position.size();
    sort(position.begin(), position.end());

    int ans=1;

    // since there will be at least a gap of 1 between any two adjacent balls
    int low=1;

    // the maximum gap between m balls 
    int high=*max_element(position.begin(), position.end())-m+1;

    while(low<=high){
        int mid=(low+high)/2;

        // If we can place all balls having a gap at least 'mid',
        if(isPossible(position, m, mid)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans; 
}

int main(){
    vector<int>position={1,2,3,4,7};
    int m=3;
    cout<<maxDistance(position, m)<<endl;

}