#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Heaters - AMAZON 2025

Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range.

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will be the same.


Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.

Input: houses = [1,5], heaters = [2]
Output: 3

*/

bool check(vector<int> &houses, vector<int> &heaters, int mid){
    int n = houses.size();
    int m = heaters.size();

    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if (abs(houses[i] - heaters[j]) <= mid){
            i++;
        }
        else{
            j++;
        }
    }
    return i == n;
}
int findRadius(vector<int> &houses, vector<int> &heaters){
    int n = houses.size();
    int m = heaters.size();

    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int maxi = max(houses[n - 1], heaters[m - 1]);

    int result = 0;

    int low = 0, high = maxi;
    while (low <= high){
        int mid = (low + high) / 2;

        if (check(houses, heaters, mid) == true){
            result = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return result;
}

int main(){
    vector<int>houses={1,2,3};
    vector<int>heaters={2};

    cout<<findRadius(houses, heaters);

}