#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an array which may contain duplicates, print all elements and their frequencies.
Input :  arr[] = {10, 20, 20, 10, 10, 20, 5, 20}
Output : { {5,1}, {10,3}, {20,4} }
*/

void countFrequency(int arr[], int n){

    // 1. brute force solution
    
    // Time Complexity : O(n^2) 
    // Auxiliary Space : O(n)

    // Mark all array elements as not visited
    vector<bool> visited(n, false);
 
    // Traverse through array elements and count frequencies
    for (int i = 0; i < n; i++) {
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }


    // 2. efficient solution

    // Time Complexity : O(n) 
    // Auxiliary Space : O(n)

    // Creating a map containing integer as a key and occurrences as a value
    map<int,int>mp;

    // Traverse through array elements and count frequencies
    for(int i=0;i<n;i++) mp[arr[i]]++;

    for(auto it:mp) cout<<it.first<<"->"<<it.second<<endl;
}

int main(){
    int n=8;
    int arr[n]={10, 20, 20, 10, 10, 20, 5, 20};
    countFrequency(arr,n);
}