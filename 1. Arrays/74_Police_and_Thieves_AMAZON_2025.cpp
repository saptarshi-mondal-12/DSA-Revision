#include <bits/stdc++.h>
using namespace std;

/* Q. Police and Thieves - AMAZON 2025

Given an array arr[], where each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police.
Keep in mind the following conditions :

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than k units away from him.

Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
Output: 2
Explanation: Maximum 2 thieves can be caught. First policeman catches first thief and second police man can catch either second or third thief.

Input: arr[] = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
Output: 3
Explanation: Maximum 3 thieves can be caught.




Intuition------------------------------------------------------------


We use two lists:
    One to store indices of policemen.
    One to store indices of thieves.

Then, we match them greedily:
    If the current policeman and thief are within k distance → match them (count++) and remove both.
    If the thief is too far left → discard thief.
    If the policeman is too far left → discard policeman.

Algorithm: 

1. Traverse the array and push indices of P in one list, indices of T in another.
2. Use two pointers (i for police, j for thieves).
3. While both lists have elements:
    If |police[i] - thief[j]| ≤ k, count++, move both pointers.
    Else if thief[j] < police[i], move j (thief too far left).
    Else move i (policeman too far left).




Follow up Question ---------------------------------------------------------------

Q. What is a policemen can catch multiple thiefs? how would you approach it ?
Ans: I’ll think of each policeman as covering a window [pos-k, pos+k]. Now I’ll try to match thieves to policemen greedily from left to right using two pointers.”

If each policeman can catch multiple thieves, I’ll treat each policeman as covering an interval [pos-k, pos+k]. Then I use a two-pointer greedy approach: traverse policemen and thieves from left to right, and whenever a thief lies within a policeman’s range, I assign him and move only the thief pointer, keeping the policeman to catch more. If the thief is too far left or right, I advance the respective pointer. This ensures we maximize the number of thieves in O(n) time.”


⚡ Key Insight

Now it’s not just "pairing policemen to thieves" (1-to-1).
It becomes more like interval coverage:
    Each policeman at index p covers the interval [p-k, p+k].
    Any thief inside this interval can be caught.
    But one thief must not be caught by 2 policemen → thieves are still unique.

So the goal is:
Maximize number of thieves caught where thieves must be unique, but policemen can catch more than one.

💡 Greedy Strategy

We can still solve this with two pointers:

1. Traverse policemen and thieves lists (their indices).
2. Compare police[i] and thief[j].

    If |police[i] - thief[j]| ≤ k, → caught!
        Count++
        Move thief pointer (j++) → because this thief is already caught.
        But do not move policeman (he can still catch more thieves!).

    Else if thief[j] < police[i] - k → thief is too far left, can’t be caught → move 
        j++

    Else if thief[j] > police[i] + k → this thief is too far right for current policeman → move 
        i++ (next policeman).

Example

arr = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
    Police at 2 can catch thieves at indices 0,1,4.
    Police at 3 can catch thief at 4 (but already caught by policeman 2, so skip).
    Police at 5 can also catch thief 4 (but already caught).
Total caught = 3.

*/


// Original question -------------------------------------
int catchThieves(vector<char> &arr, int k){
    // Code here
    int n = arr.size();

    vector<int> police, thief;

    // Store indices of policemen and thieves
    for (int i = 0; i < n; i++){
        if (arr[i] == 'P')
            police.push_back(i);
        else if (arr[i] == 'T')
            thief.push_back(i);
    }

    int i = 0, j = 0, caught = 0;

    while (i < police.size() && j < thief.size()){
        // If the current policeman and thief are within k distance → match them (caught++) and remove both.
        if (abs(police[i] - thief[j]) <= k){
            caught++;
            i++;
            j++;
        }
        // move j if thief too far left
        else if (thief[j] < police[i] - k){
            j++;
        }
        // move i if policeman too far left
        else{
            i++;
        }
    }

    return caught;
}



// Follow up --------------------------------------------
int catchThievesMultiple(vector<char>& arr, int k) {
    vector<int> police, thief;
    int n = arr.size();

    // Collect positions
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P') police.push_back(i);
        else if (arr[i] == 'T') thief.push_back(i);
    }

    int i = 0, j = 0, caught = 0;

    while (i < police.size() && j < thief.size()) {
        if (abs(police[i] - thief[j]) <= k) {
            caught++;
            j++;  // thief caught, policeman stays for next thief
        }
        else if (thief[j] < police[i] - k) {
            j++;  // thief too far left, discard
        }
        else {
            i++;  // policeman can't reach thief, move to next policeman
        }
    }
    return caught;
}


int main(){
    vector<char> arr = {'P', 'T', 'T', 'P', 'T'};
    int k = 1;
    cout << catchThieves(arr, k) << endl;
}