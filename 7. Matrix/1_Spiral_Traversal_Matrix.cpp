#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Spiral Traversal of Matrix
Given a Matrix, print the given matrix in spiral order.

Input: Matrix[][] = {{ 1, 2, 3, 4 },
		            { 5, 6, 7, 8 },
		            { 9, 10, 11, 12 },
	                { 13, 14, 15, 16 }}

Output: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Input: Matrix[][] = {{1, 2, 3 },
	                { 4, 5, 6 },
		            { 7, 8, 9 }}
			    
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.
*/

void spiralTraversal(vector<vector<int>> &matrix, int r, int c){
	// Time complexity - O(r*c)
	// space complexity - OO(r*c)

	vector<int>ans;

	int top=0, down=r-1, left=0, right=c-1;
	int direction=0;
	while(top<=down && left<=right){

		if(direction==0){
			for(int i=left;i<=right;i++){
				ans.push_back(matrix[top][i]);
			}
			top++;
		}
		else if (direction==1){
			for(int i=top;i<=down;i++){
				ans.push_back(matrix[i][right]);
			}
			right--;
		}
		else if (direction==2){
			for(int i=right;i>=left;i--){
				ans.push_back(matrix[down][i]);

			}
			down--;
		}
		else if (direction==3){
			for(int i=down;i>=top;i--){
				ans.push_back(matrix[i][left]);

			}
			left++;
		}

		direction=(direction+1)%4;
	}

	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}



int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int r = matrix.size();
    int c = matrix[0].size(); 

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;


	spiralTraversal(matrix,r,c);
}