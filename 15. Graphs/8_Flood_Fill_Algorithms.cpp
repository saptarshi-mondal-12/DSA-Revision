#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Flood Fill

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:
    1. Begin with the starting pixel and change its color to color.
    2. Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
    3. Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
    4. The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.
[1,1,1]              [2,2,2]
[1,1,0]   -------->  [2,2,0]
[1,0,1]              [2,0,1]


*/


void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>&ans, int color, int iniColor){
    // color with new color
    ans[row][col]=color;
    int n=image.size();
    int m=image[0].size();

    // Traversing all 4 neighbours (up, right, down, left) 
    int r=row-1, c=col;
    if(r>=0 && r<n && c>=0 && c < m && image[r][c] == iniColor && ans[r][c] != color) {
        dfs(r, c, image, ans, color, iniColor); 
    }
    r=row, c=col+1;
    if(r>=0 && r<n && c>=0 && c < m && image[r][c] == iniColor && ans[r][c] != color) {
        dfs(r, c, image, ans, color, iniColor); 
    }
    r=row+1, c=col;
    if(r>=0 && r<n && c>=0 && c < m && image[r][c] == iniColor && ans[r][c] != color) {
        dfs(r, c, image, ans, color, iniColor); 
    }
    r=row, c=col-1;
    if(r>=0 && r<n && c>=0 && c < m && image[r][c] == iniColor && ans[r][c] != color) {
        dfs(r, c, image, ans, color, iniColor);  
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // Time complexity: O(NxM + NxMx4) --->For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.

    // Space complexity: O(N x M) + O(N x M) ---> O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 

    int n=image.size();
    int m=image[0].size();
    int iniColor=image[sr][sc];
    vector<vector<int>>ans=image;
    dfs(sr, sc, image, ans, color, iniColor);
    return ans;
}

int main(){
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
    int sr = 1, sc = 1, newColor = 2  ;	
	vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
}