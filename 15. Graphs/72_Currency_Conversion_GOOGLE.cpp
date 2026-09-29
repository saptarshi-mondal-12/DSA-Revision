#include <bits/stdc++.h>
using namespace std;    

/* Q. Currency Conversion - GOOGLE 2026

Given array of currency conversion rates. E.g. ['USD', 'GBP', 0.77] which means 1 USD is equal to 0.77 GBP
an array containing a 'from' currency and a 'to' currency
Given the above parameters, find the conversion rate that maps to the 'from' currency to the 'to' currency.
Your return value should be a number.

Example:
You are given the following parameters:

Rates: ['USD', 'JPY', 110] ['US', 'AUD', 1.45] ['JPY', 'GBP', 0.0070]
To/From currency ['GBP', 'AUD']
Find the rate for the 'To/From' curency. In this case, the correct result is 1.89.

--------------------------------------------------------------------------------------------------

intuition: we can represent the currency conversion rates as a graph where each currency is a node and the conversion rates are edges with weights. We can use BFS or DFS to traverse the graph and find the conversion rate from the 'from' currency to the 'to' currency.

*/

double currencyConversion(int n, vector<tuple<string, string, double>> rates, string from, string to){
    // Time complexity: O(V + E) where V is the number of currencies and E is the number of conversion rates
    // Space complexity: O(V + E) for the adjacency list and visited set

    // 1. Creating adjacency list
    unordered_map<string, vector<pair<string, double>>> adj;
    for(int i=0;i<rates.size();i++){
        string u = get<0>(rates[i]);
        string v = get<1>(rates[i]);
        double w = get<2>(rates[i]);
        adj[u].push_back({v, w});
        adj[v].push_back({u, 1/w});
    }

    /* it look like this:
    Key       Value
    -------------------------------
    "USD"  →  { {"JPY",110}, {"AUD",1.45} }
    "JPY"  →  { {"USD",1/110}, {"GBP",0.007} }
    "AUD"  →  { {"USD",1/1.45} }
    "GBP"  →  { {"JPY",1/0.007} }
    */


    // 2. Check if the 'from' and 'to' currencies exist in the adjacency list
    if(!adj.count(from) || !adj.count(to)) return -1;


    // 3. BFS to find the conversion rate
    queue<pair<string, double>> q;
    unordered_set<string> visited;

    q.push({from, 1.0});
    visited.insert(from);

    while(!q.empty()){
        auto currency = q.front().first;
        auto rate = q.front().second;
        q.pop();

        // If we reach the target currency, return the conversion rate
        if(currency == to) return rate;

        for(auto &neighbor : adj[currency]){
            // if the neighbor currency has not been visited, add it to the queue
            if(!visited.count(neighbor.first)){
                visited.insert(neighbor.first);
                q.push({neighbor.first, rate * neighbor.second});
            }
        }
    }

    return -1; // If no conversion path is found
}

int main(){
    int n = 3; // Types of currencies

    vector<tuple<string, string, double>> rates = {
        {"USD", "JPY", 110},
        {"USD", "AUD", 1.45},
        {"JPY", "GBP", 0.0070}
    };

    cout<<currencyConversion(n, rates, "GBP", "AUD")<<endl;
}


