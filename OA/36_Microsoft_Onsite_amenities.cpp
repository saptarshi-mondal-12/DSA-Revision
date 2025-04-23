#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Amenities -> Microsoft onsite question 

Given cities n from 0 to N-1 in a doubly link manner, also given number of amenities m (0 to m-1 for each city). Also, given a matrix amenities of N x M where amenities [i][j] = 1 denotes amenity is present and 0 means amenity is not present. Distance between any two adjacent city is 1.

Find a city which has smallest distance to access all amenities.
Eg:int n = 5, m = 3;
vector<vector> inp = {
    {1, 0, 0},
    {0, 0, 0},
    {1, 1, 0},
    {0, 1, 0},
    {0, 0, 1}
};
ans = 3 (city 3 has dist 1 to access all amenities)
*/

int checkLeft(int i, int jth_amenity, vector<vector<int>> req, int n, int m){
    int distance = 0;
    // Flag checks that if we get jth_amenity amenity or not 
    bool flag = false;
    for(int t=i-1; t>=0; t--){
        if(req[t][jth_amenity] == 1){
            distance++;
            flag=true;
            break;

        }else{
            distance++;
        }
    }
    if(flag){
        return distance;
    }
    return 0;
}

int checkRight(int i, int jth_amenity, vector<vector<int>> req, int n, int m){
    int distance = 0;
    // Flag checks that if we get jth_amenity amenity or not 
    bool flag = false;
    for(int t=i+1; t<n; t++){
        if(req[t][jth_amenity] == 1){
            distance++;
            flag=true;
            break;

        }else{
            distance++;
        }
    }
    if(flag){
        return distance;
    }
    return 0;
}

int Smallestdistance(vector<vector<int>> req, int n, int m){ 
    // Time Complexity: O(n² * m)
    // Space Complexity: O(1)

    int result = INT_MAX;
    int apartment = -1;

    for(int i = 0; i < n; i++){
        int farthestDistanceToAceessAllAmmenities = 0;  // Moved here

        for(int j = 0; j < m; j++){
            if(req[i][j] == 0){
                // checking to left of current house 
                int farLeft = checkLeft(i, j, req, n, m);

                // checking to right of current house 
                int farRight = checkRight(i, j, req, n, m);

                // cout<<farLeft<<" "<<farRight<<endl;

                farthestDistanceToAceessAllAmmenities = max({farthestDistanceToAceessAllAmmenities, farLeft, farRight});
            }
        }

        // For ith apartment/block the maximum distance travel to access all amenities ----> Our aim is to minimize the maximum distances to access all amenities.
        if(farthestDistanceToAceessAllAmmenities < result){
            result = farthestDistanceToAceessAllAmmenities;
            apartment = i;
        }
    }


    return apartment;
}

int main(){
    int n=5, m=3;
    vector<vector<int>> req = {
        {0, 1, 0}, 
        {1, 0, 0}, 
        {1, 1, 0}, 
        {0, 1, 0}, 
        {0, 1, 1} 
    };
    cout<<Smallestdistance(req, n, m)<<endl; // apartment 3 {0, 1, 0},  with a max distance 1 to access all amenities (ie 1 left & 1 right)
}