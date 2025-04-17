#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/* Q. Maximal Rectangle 
Think every row as histogram and calculate max area
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

row 0 = histogram=[1 0 1 0 0]
row 1 = histogram [2 0 2 1 1] (if row[1][j]==1 add +1 else 0)
row 2 = histogram [3 1 3 2 2]

store ans in result
     
*/


vector<int>prevSmallerElement(vector<int>v, int col){
    stack<int>s;
    s.push(-1);
    vector<int> result(col);

    for(int i=0;i<col;i++){
        int curr=v[i];

        while(s.top()!=-1 && v[s.top()]>=curr){
            s.pop();
        }
        result[i]=s.top();
        s.push(i);
        
    }
    return result;
}

vector<int>nextSmallerElement(vector<int>v, int col){
    stack<int>s;
    s.push(-1);
    vector<int> result(col);

    for(int i=col-1;i>=0;i--){
        int curr=v[i];

        while(s.top()!=-1 && v[s.top()]>=curr){
            s.pop();
        }
        result[i]=s.top();
        s.push(i);
        
    }
    return result;
}

int maxArea(vector<int>v, int n){

    vector<int>prev(n);
    prev=prevSmallerElement(v,n);

    vector<int>next(n);
    next=nextSmallerElement(v,n);

    int area=INT16_MIN;
    for(int i=0; i<n;i++){
        int l=v[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        int newArea=l*b;
        area=max(area,newArea);
    }
    return area;
}


int maximumRectangle(vector<vector<int>>arr){
    // Time complexity - O(n * (row*col) )
    // space complexity - O(n)
    
    int row=arr.size();
    int col=arr[0].size();

    vector<int>heights(col);

    int result=0;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (arr[i][j]==1){
                heights[j]+=1;
            }else{
                heights[j]=0;
            }
        }
        int area=maxArea(heights,col);
        result=max(result,area);
    }
    return result;

}

int main(){
    vector<vector<int>>arr={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout<<maximumRectangle(arr)<<endl;
}