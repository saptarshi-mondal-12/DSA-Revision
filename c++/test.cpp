#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int s(int n , int k){
    return n%k;
}

int main(){
    int n=-3, k=5;
    cout<<s(n,k)<<endl;
}