#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* SPIRAL MATRIX III

You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

*/


// Time complexity: O(max(rows,cols)^2)
// Space complexity: O(rows*cols)

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;

        // Initial step size is 1 and direction represent current direction
        int step = 1;
        int direction = 0;
        int count = 0;

        while (result.size() < rows * cols) {
            // move left -> right (EAST)
            if (direction == 0) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                    cStart += 1;
                }
                count += 1;
            }
            // move top -> down (SOUTH)
            else if (direction == 1) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                    rStart += 1;
                }
                count += 1;
            }
            // move right -> left (WEST)
            else if (direction == 2) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                    cStart -= 1;
                }
                count += 1;
            }
            // move down -> top (NORTH)
            else if (direction == 3) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                    rStart -= 1;
                }
                count += 1;
            }

            // changing direction
            direction = (direction + 1) % 4;

            if (count % 2 == 0) {
                step += 1;
            }
        }

        return result;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> result = sol.spiralMatrixIII(5, 6, 1, 4);

    cout << "Output: ";
    for (const auto& pos : result) {
        cout << "[" << pos[0] << "," << pos[1] << "] ";
    }
    cout << endl;
    return 0;
}
