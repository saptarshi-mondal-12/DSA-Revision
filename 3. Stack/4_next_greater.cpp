#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/* Next Greater element

The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, 
which is greater than 'x'.If no greater elements exist to the right of 'x', consider the next greater element as -1.

*/




void nextGreater(int arr[], int n){
    // time complexity = O(n)
    // space complexity = O(n)
    
    stack<int>s;

    vector<int>result(n,-1);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];

        while(!s.empty() && s.top() <= curr){
            s.pop();
        }
        
        if (!s.empty()){
            result[i]=s.top();
        }
        s.push(curr);
    }

    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n=6;
    int arr[n]={5,7,1,2,6,0}; 
    nextGreater(arr,n);
}
