#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void check(){
    priority_queue<pair<int, int>> pq;
    pq.push({1,12});
    pq.push({2,2});
    pq.push({3,1});
    pq.push({4,2});
    pq.push({5,7});
    pq.push({6,3});
    pq.push({8,2});

    while(!pq.empty()){
        int a=pq.top().first;
        int b=pq.top().second;

        cout<<a<<" "<<b<<endl;

        pq.pop();
    }
}

int main(){
    check();

}