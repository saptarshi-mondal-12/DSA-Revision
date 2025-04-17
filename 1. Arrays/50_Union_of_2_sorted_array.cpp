#include<bits/stdc++.h>
using namespace std;
/*
Union of Two Sorted Arrays

Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.The union of two arrays can be defined as the common and distinct elements in the two arrays. NOTE: Elements in the union should be in ascending order.

Input 1:
n = 5,m = 5.
arr1[] = {1,2,3,4,5}  
arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5} 

Input 2:
n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}

*/

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Time complexity : O(m+n)
    // Space Complexity : O(m+n)
    int n=a.size(), m=b.size();
    int i=0, j=0;
    vector<int>Union;
    while(i<n && j<m){
        if(a[i] <= b[j]){
            if(Union.size()==0 || Union.back()!=a[i]){
                Union.push_back(a[i]);
            }
            i++;
        }else{
            if(Union.size()==0 || Union.back()!=b[j]){
                Union.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n){
        if(Union.back()!=a[i]){
            Union.push_back(a[i]);
        }
        i++;
    }
    while(j<m){
        if(Union.back()!=b[j]){
            Union.push_back(b[j]);
        }
        j++;
    }
    return Union;


    // Time complexity : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time
    // Space Complexity : O(m+n)
    
    // set<int>s;
    // for(int i=0;i<a.size();i++){
    //     s.insert(a[i]);
    // }
    // for(int i=0;i<b.size();i++){
    //     s.insert(b[i]);
    // }
    // vector<int>result(s.begin(), s.end());
    // return result;

}
int main(){
    vector<int>a={1,2,3,4,5};
    vector<int>b={2,3,4,4,5};

    vector<int>result=sortedArray(a,b);
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;
}
