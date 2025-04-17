#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* Book Allocation 

Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
There are a ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. 
If the allocation of books is not possible. return -1

Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Input Format: n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result: 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/

/*
Assume the given array is {25 46 28 49 24} and number of students, M = 4. 
Now, we can allocate these books in different ways. Some of them are the following:


25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71

From the above allocations, we can clearly observe that the minimum possible maximum number of pages is 71.

Observations:


Minimum possible answer: We will get the minimum answer when we give n books of the array to n students(i.e. 
Each student will receive 1 book). Now, in this case, the maximum number of pages will be the maximum element in the array. 
So, the minimum possible answer is max(arr[]).

Maximum possible answer: We will get the maximum answer when we give all n books to a single student. 
The maximum no. of pages he/she will receive is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).

From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].*/


int countStudents(int n, vector<int>arr, int pages){
    int students=1;
    long long pagesStudent=0;
    for(int i=0;i<n;i++){
        if(pagesStudent+arr[i] <= pages){
            pagesStudent+=arr[i];
        }else{
            students+=1;
            pagesStudent=arr[i];
        }
    }
    return students;
}

int brute_findPages(int n, vector<int>arr, int m){
    // TC = O(sum-max+1) * O(n)

    if (m>n) return -1;
    /*starting with maximum value because everyone will get atleast 1
    and ans will be always lie between [high, sum(arr)] because 
    if there is 1 student he will get all books*/

    int maxi=*max_element(arr.begin(),arr.end());
    int sum=accumulate(arr.begin(), arr.end(), 0);

    for(int pages=maxi;pages<=sum;pages++){
        if(countStudents(n,arr,pages)==m){
            return pages;
        }
    }
    return -1;
}


int optimal_findPages(int n, vector<int>arr, int m){
    // TC = O(N * log(sum(arr[])-max(arr[])+1))

    if (m > n) return -1;

    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(), arr.end(), 0);

    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(countStudents(n,arr,mid)<=m){
            ans=mid;
            high=mid-1;
            
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n=4;
    vector<int> arr={12, 34, 67, 90};
    int m=2;

    // brute
    cout<<brute_findPages(n,arr,m)<<endl;

    // optimal
    cout<<optimal_findPages(n,arr,m)<<endl;

}