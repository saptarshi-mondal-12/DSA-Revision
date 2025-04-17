#include<iostream>
using namespace std;

// pass by reference (change)  "&"
// it changes the original value in the memory 

void doSum(int &num){
    cout<<num<<endl; // 10
    num+=5;
    cout<<num<<endl; // 15
    num+=5;
    cout<<num<<endl; // 20
}

int main(){

    int num=10;
    doSum(num);
    cout<<num<<endl; // 20
    
}

