#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Ninja Training

A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn.

Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.

Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.

Input: arr[]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.




Intuition:-------------------------------------------------------------------
Q. Why a Greedy Solution doesn’t work?
The first approach that comes to our mind is the greedy approach. We will see with an example how a greedy solution doesn’t give the correct solution.

Consider this example: 
[10,50,1]
[5,100,11]

We want to know the maximum amount of merit points. For the greedy approach, we will consider the maximum point activity each day, respecting the condition that activity can’t be performed on consecutive days.

On Day 0, we will consider the activity with maximum points i.e 50.
On Day 1, the maximum point activity is 100 but we can’t perform the same activity in two consecutive days. Therefore we will take the next maximum point activity of 11 points. 
Total Merit points by Greedy Solution : 50+11 = 61
As this is a small example we can clearly see that we have a better approach, to consider activity with 10 points on day0 and 100 points on day1. It gives us the total merit points as 110 which is better than the greedy solution. 

So we see that the greedy solution restricts us from choices and we can lose activity with better points on the next day in the greedy solution. Therefore, it is better to try out all the possible choices as our next solution. We will use recursion to generate all the possible choices.

Step 1: Express the problem in terms of indexes.
It is the number of days. Clearly, we have n days (from 0 to n-1), so one changing parameter which can be expressed in terms of indexes is ‘day’.

Every day we have the option of three activities(say 0,1,2) to be performed. Suppose that we are at a day_i. What is one more parameter along with the day that we must know to try out the correct choices at day_i?

It is the ‘last’ choice that we tried out on day_i+1 ( i+1 in case of top-down recursion). Unless we know the last choice we made, how can we decide whether a choice we are making is correct or not?

Now there are three options each day(say 0,1,2) which becomes the ‘last’ of the next day. If we are just starting from the day_n-1, then for the day_n-1 we can try all three options. We can say ‘last’ for day_n-1 is 3.

For e.g. 

last | Activity that can be considered for current day
0    |  1 & 2
1    |  0 & 2
2    |  0 & 1
3    |  0 & 1 & 2


(0-based indexing)
0 means task 1 is done
1 means task 2 is done
2 means task 3 is done
3 means no task are done


Step 2: Try out all possible choices at a given index.
Now let’s discuss the second parameter. The choices we have for a current day depend on the ‘last’ variable. If we are at our base case (day=0), we will have the following choices i.e 0 & 1 & 2. and return maximum all three.

last | Activity that can be considered for current day
0    |  1 & 2   | points[0][1], points[0][2]
1    |  0 & 2
2    |  0 & 1


Step 3:  Take the maximum of all choices
As the problem statement wants us to find the maximum merit points, we will take the maximum of all choices.

Tabulation: 
Declare a dp[] array of size [n][4]
First initialize the base condition values. We know that base condition arises when day = 0. Therefore, we can say that the following will be the base conditions
    dp[0][0] = max(points[0][1], points[0][2]) 
    dp[0][1] = max(points[0][0], points[0][2]) 
    dp[0][2] = max(points[0][0], points[0][1]) 
    dp[0][3] = max(points[0][0], points[0][1] and points[0][2]) 
Set an iterative loop which traverses dp array (from index 1 to n) and for every index set its value according to the recursive logic


Space optimize:
If we closely look the relation,

dp[day][last] =  max(dp[day][last],points[day][task] + dp[day-1][task])

Here the task can be anything from 0 to 3 and day-1 is the previous stage of recursion. So in order to compute any dp array value, we only require the last row to calculate it.

So rather than storing the entire 2D Array of size N*4, we can just store values of size 4(say prev). 
We can then take a dummy array, again of size 4 (say temp) and calculate the next row’s value using the array we stored in step 1.
After that whenever we move to the next day, the temp array becomes our prev for the next step.
At last prev[3] will give us the answer.

*/

// Recursion---------------------------------------------------------------------------
int solve1(int day, int lastTasksDone, vector<vector<int>>points){
    // Base case: When we reach the first day (day == 0)
    if(day==0){
        // Calculate the maximum points for the first day by choosing an activity different from the last one
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=lastTasksDone){
                maxi=max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    int maxi=0;
    // Iterate through the activities for the current day
    for(int i=0;i<=2;i++){
        if(i!=lastTasksDone){
            // Calculate the points for the current activity and add it to the maximum points obtained so far (recursively calculated)
            int totalPoints = points[day][i] + solve1(day-1, i, points);
            maxi=max(maxi, totalPoints);
        }
    }
    return maxi;
}
int ninjaTraining1(int n, vector<vector<int>> &points){
    return solve1(n-1, 3, points);
}



// Memoization--------------------------------------------------------------------------
int solve2(int day, int lastTasksDone, vector<vector<int>>points, vector<vector<int>>&dp){
    // If the result for this day and last activity is already calculated, return it
    if (dp[day][lastTasksDone] != -1){
        return dp[day][lastTasksDone];
    }

    // Base case: When we reach the first day (day == 0)
    if(day==0){
        // Calculate the maximum points for the first day by choosing an activity different from the last one
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=lastTasksDone){
                maxi=max(maxi, points[0][i]);
            }
        }
        return dp[day][lastTasksDone] = maxi;
    }

    int maxi=0;
    // Iterate through the activities for the current day
    for(int i=0;i<=2;i++){
        if(i!=lastTasksDone){
            // Calculate the points for the current activity and add it to the maximum points obtained so far (recursively calculated)
            int totalPoints = points[day][i] + solve1(day-1, i, points);
            maxi=max(maxi, totalPoints);
        }
    }
    return dp[day][lastTasksDone] = maxi;
}
int ninjaTraining2(int n, vector<vector<int>> &points){
    // Time complexity: O(N*4*3)
    // Space complexity: O(n) + O(N*4)
    vector<vector<int>>dp(n, vector<int>(4,-1));
    return solve2(n-1, 3, points, dp);
}



// Tabulation-----------------------------------------------------------------------------
int ninjaTraining3(int n, vector<vector<int>> &points){
    // Time complexity: O(N*4*3)
    // Space complexity: O(N*4)

    // Create a 2D DP table to store the maximum points, dp[i][j] represents the maximum points at day i, considering the last activity as j
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Initialize the DP table for the first day (day 0)
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);

    // if there is only day 1 then you are going pick single task which maximum has points (among all 3 task) means max(task1, task2, task3).
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1;day<n;day++){
        for(int lastTaskDone=0;lastTaskDone<=3;lastTaskDone++){
            dp[day][lastTaskDone]=0;
            int maxi=0;
            for(int task=0;task<=2;task++){
                if(lastTaskDone != task){
                    int totalPoints = points[day][task] + dp[day-1][task];
                    maxi=max(maxi, totalPoints);
                }
            }
            dp[day][lastTaskDone]=maxi;
        }
    }
    return dp[n-1][3];
}



// Space optimization---------------------------------------------------------------------
int ninjaTraining4(int n, vector<vector<int>> &points){
    // Time complexity: O(N*4*3)
    // Space complexity: O(4)

    // Initialize a vector to store the maximum points for the previous day's activities
    vector<int> prev(4, 0);

    // Initialize the DP table for the first day (day 0)
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++){
        // Create a temporary vector to store the maximum points for the current day's activities
        vector<int> temp(4, 0);
        for (int lastTaskDone = 0; lastTaskDone <= 3; lastTaskDone++){
            temp[lastTaskDone] = 0;
            int maxi=0;
            // Iterate through the tasks for the current day
            for (int task = 0; task <= 2; task++) {
                if (task != lastTaskDone) {
                    // Calculate the points for the current activity and add it to the maximum points obtained on the previous day (stored in prev)
                    int totalPoints = points[day][task] + prev[task];
                    maxi = max(maxi, totalPoints);
                }
            }
            temp[lastTaskDone]=maxi;
        }
        // Update prev with the maximum points for the current day
        prev = temp;        
    }
    return prev[3];
}



int main(){
    vector<vector<int>>points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int n=points.size();

    // Recursion
    cout<<ninjaTraining1(n, points)<<endl;

    // Memoization
    cout<<ninjaTraining2(n, points)<<endl;

    // Tabulation
    cout<<ninjaTraining3(n, points)<<endl;

    // Space optimization
    cout<<ninjaTraining4(n, points)<<endl;  
}

