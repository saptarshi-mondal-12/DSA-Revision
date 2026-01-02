#include<iostream>
#include<vector>
#include<stack>
using namespace std;
             
/* Q. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

    height
    6 |       █
    5 |     █ █
    4 |     █ █
    3 |     █ █   █
    2 | █   █ █ █ █
    1 | █ █ █ █ █ █
    +----------------
        0 1 2 3 4 5   (index)
        2 1 5 6 2 3   (value)

    Largest Rectangle (area = 10)
    Rectangle spans index 2 to 3, height = 5


    height
    6 |         █
    5 |     ▓▓▓▓▓
    4 |     ▓▓▓▓▓
    3 |     ▓▓▓▓▓   █
    2 | █   ▓▓▓▓▓ █ █
    1 | █ █ ▓▓▓▓▓ █ █
    +----------------
        0 1 2 3 4 5


*/


int brute_largestRectangleArea(int heights[], int n){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    /* 
    take a histogram and check all its left and right histogram and calculate area.(left and right is always greater than current histogram )
    eg - 2 1 5 6 2 3

    for histogram 1, all left is greater(2)  , all right is greater than 1 (5,6,2,3). so area = (length * breadth) = (1*6) = 6 [2 1 5 6 2 3]
    for histogram 5, 5*2=10  [5,6]
    
    last return maximum area
    */

    int maxArea=-1;

    for(int i=0;i<n;i++){
        int length=heights[i];
        int breath=1;

        // checking left 
        for(int l=i-1; l>=0; l--){
            if(heights[l] >= length){
                breath++;
            }else{
                break;
            }
        }

        // checking right
        for(int r=i+1; r<n; r++){
            if(heights[r] >= length){
                breath++;
            }else{
                break;
            }
        }

        int area=length*breath;
        maxArea=max(maxArea, area);
    }

    return maxArea;
}

vector<int> prevSmaller(int arr[], int n){
    stack<int> s;
    s.push(-1);
    vector<int>result(n);

    // we have to put index in stack i.e we check value - arr[s.top()]>=curr
    
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        result[i]=s.top();
        s.push(i);
    }
    return result;
}

vector<int>nextSmaller(int arr[], int n){
    stack<int>s;
    s.push(-1);
    vector<int>result(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        result[i]=s.top();
        s.push(i);
    }
    return result;
}

int optimal_largestRectangleArea(int arr[], int n){
    // Time complexity = O(n)
    // space complexity = O(n)

    vector<int> prev(n);
    prev=prevSmaller(arr,n);

    vector<int>next(n);
    next=nextSmaller(arr,n);

    int area=INT8_MIN;
    for(int i=0;i<n;i++){
        int length=arr[i];
        if (next[i]==-1) {
            next[i]=n;
        }
        cout<<"curr="<<length<<" next["<<i<<"] = "<<next[i]<<" "<<"prev["<<i<<"] = "<<prev[i]<<endl;
        int breadth=next[i]-prev[i]-1;
        int newArea=length*breadth;
        area=max(area,newArea);
    }
    return area;
}





int main(){
    int n=6;
    int heights[n]={2,1,5,6,2,3};

    // brute
    cout<<brute_largestRectangleArea(heights,n)<<endl;

    // optimal
    cout<<optimal_largestRectangleArea(heights,n)<<endl;
}
// 2 4 2 3 = 8