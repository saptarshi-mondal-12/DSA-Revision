#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Overlapping rectangles - Microsoft

Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and the right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping. (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).

Note: It may be assumed that the rectangles are parallel to the coordinate axis.


Input: L1=(0,10), R1=(10,0), L2=(5,5), R2=(15,0)
Output: 1
Explanation: The rectangles overlap.

Input: L1=(0,2), R1=(1,1), L2=(-2,0), R2=(0,-3)
Output: 0
Explanation: The rectangles do not overlap.


Intuition -------------------------------------------------------------


1. Case 1 – Rectangle 1 is above Rectangle 2

y
^                        (x2,y2)
|       -----------------
|      |     (1)         |
|      |                 |                         ==> y1 >= b2
|****** -----------------
|(x1,y1)
|                              (a2,b2)
|****************-----------------
|               |     (2)         |
|               |                 |
|                -----------------
|          (a1,b1)
------------------------------> x



2. Case 2 – Rectangle 2 is above Rectangle 1

y
^                        (a2,b2)
|       -----------------
|      |                 |
|      |     (2)         |                         ==> b1 >= y2
|****** -----------------
|(a1,b1)
|                        (x2,y2)
|****** -----------------
|      |                 |
|      |       (1)       |
|       -----------------
| (x1,y1)
------------------------------> x






3. Case 3 – Rectangle 1 is right of Rectangle 2

y
^
|                                                 (x2,y2)
|                      (a2,b1)  -------------------
|        ----------------      |       (1)         |                                 ==> x1 >= a2
|       |    (2)         |     |                   |
|       |                |      -------------------
|        ----------------    (x1,y1)
| (a1,b1)
|
----------------------------------------------------------------------> x





4. Case 4 – Rectangle 2 is right of Rectangle 1

y
^
|
|
|                      (x2,y1)
|        ----------------                                    ==> a1 >= x2
|       |    (1)         |                  (a2,b2)
|       |                |   -----------------
|        ----------------   |     (2)         |
| (x1,y1)                   |                 |
|                            -----------------
|                        (a1,b1)
----------------------------------------------------------------------> x

*/

int doOverlap(vector<int> L1, vector<int> R1, vector<int> L2, vector<int> R2){
    // Time Complexity : O(1)
    // Space Complexity : O(1)



    // 1st rectangle coordintees
    int x1 = L1[0], y1 = L1[1]; // top-left
    int x2 = R1[0], y2 = R1[1]; // bottom-right

    // 2nd rectangle coordintees
    int a1 = L2[0], b1 = L2[1]; // top-left
    int a2 = R2[0], b2 = R2[1]; // bottom-right

    // If one rectangle is completely above or completely to the side of the other
    if (y1 <= b2)
        return 0; // case 1
    if (b1 <= y2)
        return 0; // case 2
    if (x1 >= a2)
        return 0; // case 3
    if (a1 >= x2)
        return 0; // case 4

    // Otherwise, they overlap
    return 1;
}


int main(){
    // Test case 1
    vector<int> L1 = {0, 10}, R1 = {10, 0};
    vector<int> L2 = {5, 5},  R2 = {15, 0};
    cout << doOverlap(L1, R1, L2, R2) << endl; // Expected: 1

}