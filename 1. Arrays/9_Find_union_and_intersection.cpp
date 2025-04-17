#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Find union and intersection in sortesd array 
*/

void brute_union(int n, int arr1[], int m, int arr2[]){
    // time complexity : O(n1 log n) + O(n2 log n) + O(n1+n2)
    // space complexity : O(n1+n2) 

    set<int>s;
    for(int i=0;i<n;i++) s.insert(arr1[i]);
    for(int i=0;i<m;i++) s.insert(arr2[i]);

    for(auto it:s) cout<<it<<" ";
}


void optimal_union(int n, int arr1[], int m, int arr2[]){
    // time complexity : O(n1+n2)
    // space complexity : O(n1+n2) (specially use for returning array)
    
    // using two pointer 
    vector<int> unionArr;
    int i=0, j=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;

        }else{
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j<m){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    while(i<n){
        if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    for(auto it:unionArr) cout<<it<<" ";
}


void brute_intersection(int n, int arr1[], int m, int arr2[]){
    // time complexity : O(n * m)
    // space complexity : O(m)

    vector<int>visited(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j] && visited[j]==0){
                cout<<arr1[i]<<" ";
                visited[j]=1;
                break;
            }
            if(arr2[j] > arr1[i]) break;
        }
    }
}

void optimal_intersection(int n, int arr1[], int m, int arr2[]){
    // time complexity : O(n+m) in worst case
    // space complexity : O(1)

    // using two pointer
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]) i++;
        else if(arr2[j] < arr1[i]) j++;
        else {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
}

int main(){
    int n=7;
    int arr1[n]={1,1,2,3,4,4,5};
    int m=6;
    int arr2[m]={2,3,4,4,5,6};

    // Q. Find Union

    // 1. Brute force
    // brute_union(n,arr1,m,arr2);

    // 2. optimal force
    optimal_union(n,arr1,m,arr2);

    

    
    // Q. Finding Intersection

    // 1. brute force
    // brute_intersection(n,arr1,m,arr2);

    // 2. optimal force
    // optimal_intersection(n,arr1,m,arr2);

}