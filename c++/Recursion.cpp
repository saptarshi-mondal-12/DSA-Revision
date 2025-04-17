#include<bits/stdc++.h>
using namespace std;

// Recursion - when a function calls itself until a specific condition is met

int cnt=0;
void f(){
    if(cnt==3) return;
    cout<<cnt<<endl; // 0 1 2
    cnt++;
    f();

}

void print_name(int i,int n){
    if (i>n) return;
    cout<<"SAPTARSHI MONDAL"<<endl;
    i++;
    print_name(i,n);
}

void print_naturalNumbers(int i,int n){
    if(i>n) return;
    cout<<i<<' ';
    i++;
    print_naturalNumbers(i,n);
}

void reverse_natural_number(int i,int n){
    if(i<1) return;
    cout<<i<<" ";
    i-=1;
    reverse_natural_number(i,n);
}

void sum_naturalNumbers1(int i ,int sum){
    // parameterized function

    if(i<1){
        cout<<sum<<endl;
        return;
    }
    sum_naturalNumbers1(i-1,sum+i);
}

int sum_naturalNumbers2(int n){
    if(n==0) return 0;
    return n+sum_naturalNumbers2(n-1);
}

int factorial(int n){
    if (n==0) return 1;
    return n*factorial(n-1);
}

void reverse_array(int i, int arr[], int n){
    if(i>=n/2) return ;
    swap(arr[i],arr[n-i-1]);
    reverse_array(i+1,arr,n);
}

bool palindrome(int i,string s){
    if(i>=s.size()) return true;

    if(s[i]!=s[s.size()-i-1]) return false;
    return palindrome(i+1,s);
}

int fibonacii(int n){
    if (n<=1) return n;
    return fibonacii(n-1)+fibonacii(n-2);
}


int main(){
    // f();

    // 1. print name 5 times
    int n=4;
    // print_name(1,n);

    // 2. print 1 to n
    // print_naturalNumbers(1,n);

    // 3. print n - 1
    // reverse_natural_number(n,n);

    // 4. sum of n natural numbers
    // sum_naturalNumbers1(n,0);
    // cout<<sum_naturalNumbers2(n);

    // 5. factorial of n
    // cout<<factorial(n)<<endl;

    // 6. reverse array
    // int n=5;
    // int arr[n]={1,2,3,4,5};
    // reverse_array(0,arr,n); // 5 4 3 2 1

    // 7. check palindrome tc O(n/2)
    // string s="abccuba";
    // if(palindrome(0,s)) cout<<"palindrome"<<endl;
    // else cout<<"not a palindrome"<<endl;

    // multiple recursive call

    // 1. fibonacii  tc=O(2^n) exponential 
    // cout<<fibonacii(n)<<endl;










}
