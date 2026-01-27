#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum Population Year - Amazon 2025

You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.


Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.

Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960
Explanation: The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.


Intuition:
----------------------------------------------------------------------   
    The key observation in this problem is that population only changes at specific years—when someone is born or when someone dies. Between these events, the population remains constant. Therefore, instead of counting the population separately for every person and every year, we can track how the population changes over time.

    Each person contributes:
        +1 population starting from their birth year

        –1 population starting from their death year, because the death year itself is excluded ([birth, death − 1])

    This naturally leads to the difference array / prefix sum approach.

    How the Idea Works

        1. Mark population changes
            a. At birthi, population increases by 1.
            b. At deathi, population decreases by 1 (since the person is not alive in that year).

            Instead of updating every year in between, we only record these two changes.

        2. Accumulate changes year by year
            a. By taking a prefix sum over years, we reconstruct the actual population for each year.
            b. While doing this, we keep track of:
                the maximum population seen so far
                the earliest year when this maximum occurs.

        3. Why this works efficiently
            a. The year range is small (1950–2050), so iterating over all years is inexpensive.
            b. Each log is processed once, and each year is processed once.

    Example Walkthrough (Example 2):

    logs = [[1950,1961],[1960,1971],[1970,1981]]

    Population changes:

        1950 → +1
        1961 → −1
        1960 → +1
        1971 → −1
        1970 → +1
        1981 → −1

    Prefix sum over years:
        1950–1959 → population = 1
        1960–1961 → population = 2 (maximum first occurs at 1960)
        1970–1971 → population = 2 again, but we keep 1960 since the problem asks for the earliest year.
*/

int maximumPopulation(vector<vector<int>>& logs) {
    // Time Complexity: O(N + Y) where N is number of logs and Y is year range (101 here)
    // Space Complexity: O(Y) for difference array

    
    // Year range is small (1950 to 2050)
    vector<int> diff(2051, 0);

    // Step 1: Build difference array
    for (auto& log : logs) {
        diff[log[0]]++;   // birth year
        diff[log[1]]--;   // death year (excluded)
    }

    int maxPopulation = 0;
    int currentPopulation = 0;
    int answerYear = 0;

    // Step 2: Prefix sum over years
    for (int year = 1950; year <= 2050; year++) {
        currentPopulation += diff[year];

        if (currentPopulation > maxPopulation) {
            maxPopulation = currentPopulation;
            answerYear = year;
        }
    }

    return answerYear;
}

int main(){
    vector<vector<int>> logs = {{1993,1999},{2000,2010}};
    cout << "Maximum Population Year: " << maximumPopulation(logs) << endl;

    logs = {{1950,1961},{1960,1971},{1970,1981}};
    cout << "Maximum Population Year: " << maximumPopulation(logs) << endl;

}