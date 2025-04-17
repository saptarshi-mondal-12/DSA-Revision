#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* K-th Element of Two Sorted Arrays 

Given two sorted arrays of size m and n respectively, you are tasked with finding the element 
that would be at the kth position of the final sorted array.

Input: m = 5, n = 4, array1 = [2,3,6,7,9], array2 = [1,4,8,10], k = 5
Output:6
Explanation: Merging both arrays and sorted. Final array will be - [1,2,3,4,6,7,8,9,10]. We can see at k = 5 in the final array has 6. 

Input: m = 1, n = 4, array1 = [0], array2 = [1,4,8,10], k = 2
Output:4

Approach :
We can part it in such a way that our kth element will be at the end of the left half array. Let’s make some observations. 
We can see that all elements of the right half of the array are always larger than the left ones. So, with help of binary search, 
\we will divide arrays into partitions with keeping k elements in the left half. We have to keep in mind that l1 <= r2 and l2 <= r1. 
Why so? This ensures that left-half elements are always lesser than right elements.

*/

int brute_kth_Element(vector<int>nums1, vector<int>nums2, int k){
    // Time Complexity: O(k) 
    // Space complexity: O(1)
    
    int n1=nums1.size();
    int n2=nums2.size();

    int p1=0;
    int p2=0;
    int count=0;
    
    while(p1<n1 && p2<n2){
        if(nums1[p1]<=nums2[p2]){
            count++;
            if (count==k) return nums1[p1];
            p1++;
        }
        else{
            count++;
            if (count==k) return nums2[p2];
            p2++;
        }
    }
        
        
    while(p1<n1 && count<=k){
        count++;
        if (count==k) return nums1[p1];
        p1++;
    }
    while(p2<n2 && count<=k){
        count++;
        if (count==k) return nums2[p2];
        p2++;
    } 
    return 0;
}


int optimal_kth_Element(vector<int>nums1, vector<int>nums2, int k){
    // Time complexity - log(min(m,n))
    // space complexity - O(1)

    int n1=nums1.size();
    int n2=nums2.size();

    // swap it because we are going to apply binary search on nums1
    if(n1>n2){
        return optimal_kth_Element(nums2,nums1,k);
    }

    // left half
    int left=k;

    int low=max(0,k-n2);
    int high=min(k,n1);  

    while(low<=high){
        int mid1=(low+high)/2; // for array1
        int mid2=left-mid1; // for array2
            
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
            

        if (mid1-1 < n1 && mid1!=0) l1=nums1[mid1-1];
        if (mid2-1 < n2 && mid2!=0) l2=nums2[mid2-1];
        if (mid1 < n1) r1=nums1[mid1];
        if (mid2 < n2) r2=nums2[mid2];
    
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }

        // eleminates the half
        else if(l1>r2){
            high=mid1-1;
        }else{
            low=mid1+1;
        }
    }
    return 0;
}



int main(){
    vector<int>nums1={2,3,6,7,9};
    vector<int>nums2={1,4,8,10};
    int k=4;

    // 1. Brute soln 
    cout<<brute_kth_Element(nums1, nums2,k)<<endl;

    // 2. Optimal soln 
    cout<<optimal_kth_Element(nums1, nums2,k)<<endl;
}