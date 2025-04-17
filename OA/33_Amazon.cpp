#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LongestConsecutiveSequence {
    private:
        unordered_set<int> seen;                // To avoid duplicates
        unordered_map<int, int> sequenceMap;    // Maps boundaries to sequence length
        int maxLength = 0;
    
    public:
        int addNumberAndCompute(int num) {
            // Time complexity: O(1)
            // space complexity: O(n)
            
            if (seen.count(num)) return maxLength; // Skip duplicates
    
            seen.insert(num);
    
            int left = sequenceMap.count(num - 1) ? sequenceMap[num - 1] : 0;
            int right = sequenceMap.count(num + 1) ? sequenceMap[num + 1] : 0;
            int totalLength = left + 1 + right;
    
            // Update sequence boundaries
            sequenceMap[num] = totalLength;
            sequenceMap[num - left] = totalLength;
            sequenceMap[num + right] = totalLength;
    
            maxLength = std::max(maxLength, totalLength);
            return maxLength;
        }
};

int main(){
    LongestConsecutiveSequence lcs;
    cout<<lcs.addNumberAndCompute(1)<<endl; // returns 1
    cout<<lcs.addNumberAndCompute(2)<<endl; // returns 2
    cout<<lcs.addNumberAndCompute(4)<<endl; // returns 2
    cout<<lcs.addNumberAndCompute(3)<<endl; // returns 4
    cout<<lcs.addNumberAndCompute(11)<<endl; // returns 4
    cout<<lcs.addNumberAndCompute(8)<<endl; // returns 4
    cout<<lcs.addNumberAndCompute(10)<<endl; // returns 4
    cout<<lcs.addNumberAndCompute(9)<<endl; // returns 4
    cout<<lcs.addNumberAndCompute(7)<<endl; // returns 5
}


