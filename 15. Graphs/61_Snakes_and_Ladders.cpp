#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Snakes and Ladders

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
*/

vector<int> findCoordinates(int currVal, int n){
    int row = n - (currVal - 1) / n - 1;
    int col = (currVal - 1) % n;
    if (row % 2 == n % 2){
        return {row, n - 1 - col};
    }
    else{
        return {row, col};
    }
}
int snakesAndLadders(vector<vector<int>> &board){

    /* Time complexity: For each square, we check up to 6 possible moves (dice rolls). Thus, the total number of operations is O(6 * n²) = O(n²).

    Space complexity: Visited Array: O(n²) to keep track of visited squares. Queue: In the worst case, the queue can hold up to O(n²) squares (e.g., when all squares are in the queue at the same level). Overall Space Complexity: O(n²) due to the visited array and the queue.
    */
    int n = board.size();

    vector<bool> visited(n * n + 1, false);
    visited[1] = true;

    queue<pair<int, int>> q; // (square, moves)
    q.push({1, 0});

    while (!q.empty()){
        int square = q.front().first;
        int moves = q.front().second;
        q.pop();

        if (square == n * n)
            return moves;

        for (int diceVal = 1; diceVal <= 6; diceVal++){
            int nextSquare = square + diceVal;

            if (nextSquare > n * n)
                continue;

            // Finding Coordinate
            vector<int> pos = findCoordinates(nextSquare, n);
            int r = pos[0];
            int c = pos[1];

            if (board[r][c] != -1){
                nextSquare = board[r][c];
            }

            if (!visited[nextSquare]){
                visited[nextSquare] = true;
                q.push({nextSquare, moves + 1});
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };

    int result = snakesAndLadders(board);
    cout << "Minimum moves to reach the end: " << result << endl;
}