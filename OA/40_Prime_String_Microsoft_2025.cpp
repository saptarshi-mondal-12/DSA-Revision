#include<bits/stdc++.h>
using namespace std;


/* Q. Prime String

Alice has just learnt about primeStrings. A string is a primeString if the number of distinct alphabets used in the string is a prime and also the number of occurrences of each alphabet in the string is also a prime.
Given a String you need to tell if it is a primeString or not.

Input: s="ababb"
Output: "Yes"
Explanation: 2 different alphabets each occurring 2 and 3 times respectively so string "ababb" is a PrimeString.


Input:"abcab"
Output: "No"
Explanation: In second string char 'a' occurs 2 times, char 'b' occurs 2 times but char 'c' occur only 1 time which is not a prime number that's why string "abcab" is not a PrimeString.

Input:"aabbccdd"
Output: "No"
Explanation: String contains 4 distinct alphabets and 4 is not a prime Number so the string "aabbccdd" is not a PrimeString.

*/


unordered_set<int> sievePrime(int n, unordered_set<int>&primeNumbers){
    int arr[n]={0};
    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            for(int j=i*i;j<=n;j+=i){
                arr[j]=1;
            }
        }
    }

    for(int i=2;i<n;i++){
        if(arr[i]==0){
            primeNumbers.insert(i);
        }
    }

    // for(auto it: primeNumbers){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    return primeNumbers;
}


// Sieve function: returns a boolean array where isPrime[i] = true if i is prime
vector<bool> sievePrime(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

bool isPrimeString(string s) {
    /* 
    🔹 Complexity Analysis:
            Sieve Precomputation: O(n log log n)
            Building frequency map: O(n)
            Checking frequencies: O(σ) (σ = alphabet size ≤ 256, constant)
            Final check: O(1)

        ✅ Total Time: O(n log log n)
        ✅ Space: O(n) (boolean array + frequency map)
    */

    
    int n = s.size();

    // Precompute primes up to n (since max freq = n)
    vector<bool> isPrime = sievePrime(n);

    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }

    // Check if every frequency is prime
    for (auto &it : mp) {
        if (!isPrime[it.second]) {
            return false;
        }
    }

    // Check if number of distinct alphabets is prime
    int no_of_distinct_alphabets = mp.size();
    return isPrime[no_of_distinct_alphabets];
}

int main(){
    string s = "aabbccdd";

    bool ans = isPrimeString(s);

    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}