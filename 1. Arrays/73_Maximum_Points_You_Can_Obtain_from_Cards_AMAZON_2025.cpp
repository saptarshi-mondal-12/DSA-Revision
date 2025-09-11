#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum Points You Can Obtain from Cards - AMAZON 2025

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.


Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

*/

int maxScore(vector<int> &cardPoints, int k){
    int n = cardPoints.size();
    int maximumScore = 0;

    if (k == 1){
        maximumScore = max(cardPoints[0], cardPoints[n - 1]);
        return maximumScore;
    }

    // if k is equal to n
    if (k == n){
        for (int i = 0; i < n; i++){
            maximumScore += cardPoints[i];
        }
        return maximumScore;
    }

    int first_k_sum = 0;
    int last_k_sum = 0;

    int i = 0;
    int j = n - 1;
    int index = 0;
    while (index < k){
        first_k_sum += cardPoints[i];
        i++;
        last_k_sum += cardPoints[j];
        j--;
        index++;
    }

    maximumScore = max(maximumScore, max(first_k_sum, last_k_sum));

    int score = first_k_sum, lastIndex = n - 1;

    for (int i = k - 1; i >= 0; i--){
        score -= cardPoints[i];
        score += cardPoints[lastIndex];
        lastIndex--;
        maximumScore = max(maximumScore, score);
    }

    return maximumScore;
}

int main(){
    vector<int>cardPoints={1,2,3,4,5,6,1};
    int k=3;

    cout<<maxScore(cardPoints, k);
}