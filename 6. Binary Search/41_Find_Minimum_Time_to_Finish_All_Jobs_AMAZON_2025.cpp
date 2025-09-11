#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Find Minimum Time to Finish All Jobs - AMAZON 2025

You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

Return the minimum possible maximum working time of any assignment.


Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.

Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.


--------------------------------------------------------------------------------

Intuition

This function is just DFS (backtracking):
    Place the current job into one worker.
    Recurse for the next job.
    If all jobs fit, success.
    If any worker overflows, backtrack and try a different worker.

It’s basically like:
    “Can I fit all jobs into k buckets of capacity mid?”
    Where each job must go into exactly one bucket.


jobs = [8, 7, 4, 2, 1], k = 2, mid = 11

Start with idx=0 (job=8).
    Try worker0 → workers = [8, 0].

    Recurse with idx=1 (job=7).
        Try worker0 → workers = [15, 0] ❌ exceeds mid → reject.
        Try worker1 → workers = [8, 7].

            Recurse with idx=2 (job=4).
                Try worker0 → workers = [12, 7] ❌ reject.
                Try worker1 → workers = [8, 11].

                    Recurse with idx=3 (job=2).
                        Try worker0 → workers = [10, 11].

                            Recurse with idx=4 (job=1).
                                Try worker0 → workers = [11, 11] ✅ success! return true.

Thus, canAssign returns true for mid=11.
So binary search knows that 11 is feasible.

👉 In short:
canAssign is a recursive feasibility checker that tests if jobs can be distributed without exceeding mid. It’s like trying to “pack” jobs into workers, backtracking whenever we hit an overflow.

                        [0,0]
                           |
                      assign 8
                           ↓
                        [8,0]
                           |
                      assign 7
                  ┌────────┴────────┐
          [15,0] X (reject)     [8,7]
                                    |
                               assign 4
                         ┌─────────┴─────────┐
                   [12,7] X              [8,11]
                                              |
                                         assign 2
                                    ┌─────────┴─────────┐
                              [10,11]               [8,13] X
                                    |
                               assign 1
                          ┌─────────┴─────────┐
                     [11,11] ✅ SUCCESS   [10,12] X


Example Walkthrough with Return and Backtrack

Take a smaller example:

jobs = [5, 3], k = 2, mid = 5

Step 1: Assign job=5 to worker0
workers = [0,0]
workers[0] += 5 → [5,0]


Recursive call for next job (idx=1).

Step 2: Assign job=3
workers = [5,0]
→ Try worker0: 5+3 = 8 > 5 ❌ skip
→ Try worker1: 0+3 = 3 ≤ 5 → [5,3]


Recursive call for idx=2.

Step 3: Base case
idx == jobs.size() → return true


So recursion bubbles up success.
No need to undo because we are returning immediately.

Now suppose instead:

jobs = [6, 3], k = 1, mid = 6

Step 1: Assign job=6 to worker0
workers = [0]
workers[0] += 6 → [6]


Recursive call for next job.

Step 2: Assign job=3
workers = [6]
→ Try worker0: 6+3 = 9 > 6 ❌ skip


No valid assignment → return false.
Before trying another worker, we must undo:

workers[0] -= 6 → [0]


Now loop ends (no more workers to try) → return false all the way up.

Visualization of Return/Backtrack Flow
assign job to worker
    |
    ├── if recursive call succeeds → return true immediately (no undo)
    |
    └── if recursive call fails → undo assignment, try next worker

🔑 Takeaway

return true = found a valid assignment, stop everything.

workers[i] -= jobs[idx] = only runs when recursion failed, so we must restore state before exploring the next worker.


✅ Feasibility Check (canAssign)

This is where backtracking DFS comes in.    
    Think of it as placing each job into one of the k buckets (workers).
    Each bucket has capacity = mid.
    If at the end all jobs fit → feasible, else not.

How it works
    Start with the largest job (sorting descending helps pruning).
    For each job, try assigning it to every worker:
        If workers[i] + jobs[idx] <= mid, assign it.
        Recurse to the next job.
        If recursion succeeds, bubble up true.
        If it fails, undo assignment (backtrack) and try another worker.
    If no worker can take the job, return false.

🧠 Intuition Behind Backtracking

Backtracking is like exploring possibilities in a decision tree:
    At each step, place the current job somewhere.
    If that path eventually fails (dead end), rewind (undo the move) and try a different path.
    Stop as soon as you find one full successful assignment.

Think of it as:
    Try a door → go inside → if it leads to treasure, stop.
    If it’s a dead end, backtrack out and try another door.



Follow up: ------------------------------------------------------------------------------

Q. rather that choosing a task in subsequence i had to use it in subarray


🔴 New twist: Subarray constraint

Instead of splitting jobs arbitrarily, you must divide the array into k contiguous subarrays.
Each worker gets exactly one subarray.
Goal = minimize the maximum sum of any worker’s subarray.

This changes everything.

Now it becomes the “Split Array Largest Sum” problem (LeetCode #410).
Much simpler than the original version.

✅ Approach

We use binary search on the answer + greedy checking.

    Step 1: Search space
        Low = max(jobs) (a worker must at least handle the heaviest job).
        High = sum(jobs) (one worker does all).

    Step 2: Feasibility check (canSplit)

Given a limit mid, check if we can split into ≤ k subarrays such that no subarray sum exceeds mid

*/



bool canAssign(vector<int> &jobs, vector<int> &workers, int idx, int k, int mid){
    if (idx == jobs.size())
        return true;

    for (int i = 0; i < k; i++){
        if (workers[i] + jobs[idx] <= mid){
            workers[i] += jobs[idx];
            if (canAssign(jobs, workers, idx + 1, k, mid)){
                return true;
            }
            else{
                workers[i] -= jobs[idx];
            }
        }
        // if worker[i] was 0 and couldn't fit this job, no point trying other empty workers
        if (workers[i] == 0)
            break;
    }
    return false;
}
bool checkPossible(vector<int> &jobs, int k, int mid){
    vector<int> workers(k, 0);
    return canAssign(jobs, workers, 0, k, mid);
}
int minimumTimeRequired(vector<int> &jobs, int k){
    /* Time complexity: O(log(sum(jobs)) * k^n)
    
    1. Sort jobs once in descending order: O(n log n).
    2. Binary search on answer (mid) over the range [max(jobs), sum(jobs)] -
       call the number of iterations B = O(log(sum(jobs))).
    3. For each mid, run a backtracking feasibility check canAssign(...) which tries to put each of the n    jobs into one of k workers with pruning.
    4. Cost of the backtracking check (per mid) = O(k^n) (worst case).


    Space complexity: O(k+n)

    workers array: O(k)
    recursion stack: depth n → O(n)
    */

    int n = jobs.size();

    // assign bigger jobs first
    // we assign the most time consuming job first.
    sort(jobs.begin(), jobs.end());

    int low = *max_element(jobs.begin(), jobs.end());
    int high = accumulate(jobs.begin(), jobs.end(), 0);

    int result = high;

    while (low <= high){
        int mid = (low + high) / 2;
        if (checkPossible(jobs, k, mid)){
            result = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return result;
}




// Follow up ------------------------------------------------------------------

bool canSplit(vector<int>& jobs, int k, int mid) {
    int workers = 1;  // start with 1 worker
    int currSum = 0;

    for (int job : jobs) {
        if (currSum + job <= mid) {
            currSum += job;
        } else {
            workers++;
            currSum = job;
            if (workers > k) return false;
        }
    }
    return true;
}
int follow_up_minimumTimeRequired(vector<int>& jobs, int k) {
    int low = *max_element(jobs.begin(), jobs.end());
    int high = accumulate(jobs.begin(), jobs.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canSplit(jobs, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}


int main(){
    vector<int> jobs = {1, 2, 4, 7, 8};
    int k = 2;

    // original question
    // cout << minimumTimeRequired(jobs, k) << endl;


    // follow up question - rather that choosing a task in subsequence i had to use it in subarray
    cout << follow_up_minimumTimeRequired(jobs, k) << endl;

}