#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void digitCount(int n){
    //  time complexity - O(n)
    int count=0;
    while(n!=0){
        n=n/10;
        count+=1;
    }
    cout<<"No of digit = "<<count<<endl;
}

void reverse_number(int n){
     //  time complexity - O(n)
    int temp=n;
    int reverse=0;
    while(temp!=0){
        int last=temp%10;
        reverse=reverse * 10 + last;
        temp=temp/10;
    }
    cout<<"reverse of "<<n<<" is = "<<reverse<<endl;
}

void check_palindrome(int n){
    // 1. we reverse the number 
    // 2. compare the orioginal with reverse number. if both are same the number is palindrome

    // Time Complexity: O(N) for reversing N digits of input integer.
    
    int reverse =0;
    int temp=n;
    while(temp!=0){
        int last = temp%10;
        reverse=reverse*10+last;
        temp=temp/10;
    }
    if(n==reverse){
        cout<<n<<" is a palindrome"<<endl;
    }
    else{
        cout<<n<<" is not a palindrome"<<endl;
    }
}

void GCD(){
    //  greatest number theat divides both number
    //  time complexity - O(n)
    
    int a=4;
    int b=8;
    int result;
    
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            result=i;
        }
    }
    cout<<"the GCD of the two number is = "<<result<<endl;

    // using EUCLIDEAN'S THEOREM  
    // gcd(a,b) = gcd(a%b,b) where a>b
    //  Time Complexity: O(logɸ min(a,b)), where ɸ is 1.61.
    while (a>0 && b>0){
        if (a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) cout<<"the GCD of the two number is = "<<b<<endl;
    else cout<<"the GCD of the two number is = "<<a<<endl;

}

void check_armstrong(int n){
    /*Armstrong Numbers are the numbers having the sum of digits raised to 
    power no. of digits is equal to a given number. Examples- 0, 1, 153, 370, 
    371, 407, and 1634 are some of the Armstrong Numbers.*/

    // 1. count no of digit
    int count=0;
    int temp=n;
    while(temp!=0){
        count+=1;
        temp=temp/10;
    }

    int temp1=n;
    int result=0;
    while(temp1!=0){
        int last = temp1%10;
        result+=pow(last,count);
        temp1=temp1/10;
    }
    if(result==n) cout<<n<<" is a armstrong"<<endl;
    else cout<<n<<" is not a armstrong"<<endl;

    //  Time complexity - O(n)

}

void printAllDivisor(int n){

    // brute force
    // time complexity - O(n)
    
    for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<" ";
    }
    cout<<endl;

    // optimize soln
    //  time complexity - O(sqrt(n)) + O(nlogn)) 

    // O(sqrt(n)) 
    vector<int>v;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if((n/i) !=i){
                v.push_back(n/i);
            }
        }
    }
    // O(n log n) where n is no of factors 
    sort(v.begin(),v.end());
    for(auto it:v) cout<< it <<" ";

}

void check_prime(int n){
    // time complexity - O(sqrt(n))
    int count=0;
    bool flag=1;
    for(int i=2;i<sqrt(n);i++){
        if (n%i==0){
            flag=0;
        }
    }
    if(flag) cout<<n<<" is a palindrome";
    else cout<<n<<" is not a palindrome";
    cout<<endl;

    // find prime in range 1 to 20
    // Sieve of Eratosthenes
    // time complexity - O(n * log( log(n) ) )
    int num=20;
    vector<int> v(num,0);
    for(int i=2;i<=num;i++){
        if(v[i]==0){
            for(int j=i*i;j<=num;j+=i){
                v[j]=1;
            }
        }
    }
    for(int i=2;i<v.size();i++){
        if(v[i]==0) cout<<i<<' ';
    }
}

int main(){
    int num=7;

    // digitCount(num);
    // reverse_number(num);
    // check_palindrome(num);
    // GCD();
    // check_armstrong(num);
    // printAllDivisor(num);
    // check_prime(num);




}
