#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count larger elements on right side of each element in an array

Input: arr[] = {3, 7, 1, 5, 9, 2} 
Output: {3, 1, 3, 1, 0, 0} 

*/

vector<int> brute_NGE(vector<int> v){
    // time complexity - O(n^2)
    // space complexity - O(1)

    int n=v.size();
    vector<int>ans;

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

vector<int> optimal_NGE(vector<int> v){

    
}

int main(){
    vector<int>v={3,7,1,5,9,2};

    // 1. brute
    vector<int>result=brute_NGE(v);

    // 2. optimal
    // vector<int>result=optimal_NGE(v);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<' ';
    }
    cout<<endl;

}