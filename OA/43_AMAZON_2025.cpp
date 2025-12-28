#include<bits/stdc++.h>
using namespace std;

/* Q. Wall Construction Problem - AMAZON 2025

You have to build a wall of dimension 3 * N for your house only with the help of stones of dimension 1 * 3. Find the number of ways in which the wall can be constructed.


---------------------------------------------------------------------------------

Step 1: Observations

1. Each stone covers 3 cells in a straight line.
    a) Either it is placed vertically (occupies 3 rows in the same column).
    b) Or it is placed horizontally (occupies 3 columns in the same row).

2. Since the wall height is 3, a vertical stone exactly fills one column.
    a) That means placing a vertical stone reduces the problem from 3 × N to 3 × (N-1).

3. If we use horizontal stones, they must come in groups of 3 rows together:
    a) To cover all 3 rows horizontally across 3 columns, we must place three horizontal stones stacked.
    b) That reduces the problem from 3 × N to 3 × (N-3).


Step 2: Recurrence relation

Let dp[n] = number of ways to build a 3 × n wall.
From the observations:

    a) If the first column is filled with 1 vertical stone → remainder is 3 × (n-1) → contributes dp[n-1].

    b) If the first 3 columns are filled with 3 horizontal stones → remainder is 3 × (n-3) → contributes dp[n-3].

So: dp[n] = dp[n−1] + dp[n−3]


Step 3: Base cases

dp[1] = 1 (only vertical stone possible).
dp[2] = 1 (only vertical stones, 2 columns).
dp[3] = 2
(either 3 vertical stones OR 3 horizontal stones stacked).


Step 4: Example computation
    dp[1] = 1
    dp[2] = 1
    dp[3] = 2
    dp[4] = dp[3] + dp[1] = 2 + 1 = 3
    dp[5] = dp[4] + dp[2] = 3 + 1 = 4
    dp[6] = dp[5] + dp[3] = 4 + 2 = 6


So the sequence is:
N:   0 1 2 3 4 5 6 7 ...
dp:  1 1 1 2 3 4 6 9 ...


Time Complexity: O(N) (just one loop up to N).
Space Complexity: O(4) 


Example: N = 4 -------------------------------------------------

✅ Case 1: All verticals

We just stack 4 vertical stones side by side (each fills height 3).

VVVV
VVVV
VVVV

✅ Case 2: First column vertical, rest horizontal stack

Place 1 vertical in the first column.
Fill the remaining 3 × 3 block with 3 horizontals stacked.

VHHH
VHHH
VHHH

✅ Case 3: First 3 columns horizontal stack, last column vertical

Fill the first 3 × 3 block with 3 horizontals stacked.
Place 1 vertical in the last column.

HHHV
HHHV
HHHV

👉 And that’s it — exactly 3 valid configurations.

So: dp[4]=3 (dp[3] + dp[1] = 2 + 1 = 3).



Example: N = 5 -------------------------------------------------

Nice — let’s list and visualize all 4 valid tilings for a 3 × 5 wall.
Recall: dp[5] = dp[4] + dp[2] = 3 + 1 = 4.

We get the 4 tilings by two choices at the left end:
    a) Put a vertical tile in column 1, then tile the remaining 3×4 in any of its dp[4]=3 ways.
    b) Put three horizontals stacked covering columns 1–3, then tile the remaining 3×2 in its dp[2]=1 way.

Below each row shows the 5 columns; V = a vertical tile occupying that whole column, H = a horizontal tile occupying 3 columns in that row.

From the vertical-first branch (3 tilings — prepend V to each 3×4 tiling)

1. All verticals:

VVVVV
VVVVV
VVVVV


2. Vertical then three stacked horizontals in columns 2–4:

VVHHH
VVHHH
VVHHH


3. Vertical + (three horizontals in cols 2–4 with a trailing vertical at col5):

VHHHV
VHHHV
VHHHV


(These three come from taking each 3×4 tiling and adding one V at the left.)
From the horizontals-first branch (1 tiling — horizontals in cols 1–3, then tile 3×2)

4. Three stacked horizontals in cols 1–3, then two verticals in cols 4–5:

HHHVV
HHHVV
HHHVV

That’s all — 4 distinct tilings, matching dp[5] = 4.

-----------------------------------------------------------------

Q. How n-1 and n-3 ?
Ans: 

🔹 Step 1: Vertical stone case
Place a vertical stone in the first column.
    A vertical stone is 1 × 3, so it fills the entire column of height 3.

V...
V...
V...

So after placing it, the remaining wall is:
    Original: 3 × 4
    After 1 vertical: 3 × 3

➡ This contributes dp[3].


🔹 Step 2: Horizontal stone case
Now suppose we try to place horizontal stones.
Each horizontal stone is 1 × 3. Since the wall has height 3, you can place one stone in row 1, one in row 2, and one in row 3, all starting from column 1.

This looks like:

HHH.
HHH.
HHH.

(where H means horizontal tile cells, . means empty).

So you filled the first 3 columns completely. Remaining wall:
    Original: 3 × 4
    After 3 horizontal stones: 3 × 1

➡ This contributes dp[1].


🔹 Step 3: Combine both: 
So recurrence for N = 4 is: dp[4] = dp[3] + dp[1]


*/

int waysToConstructWall(int N){

    if (N == 1) return 1;
    if (N == 2) return 1;
    if (N == 3) return 2;

    int a = 1; 
    int b = 1; 
    int c = 2; 
    int d = 0;

    for (int i = 4; i <= N; i++) {
        d = c + a; 
        a = b;
        b = c;
        c = d;
    }
    return d;
}

int main(){
    int     N = 7;
    cout << "Number of ways to build 3x" << N << " wall = " <<waysToConstructWall(N);
}