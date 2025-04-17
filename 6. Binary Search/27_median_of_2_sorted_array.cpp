#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

double brute_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    // Time complexity - O(n1+n2)
    // space  complexity - O(n1+n2)

    // intuition - merge the two sorted arrays and then find the median in that merged array.

    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    vector<int>nums3;
    int i=0; int j=0;
    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            nums3.push_back(nums1[i]);
            i++;
        }else{
            nums3.push_back(nums2[j]);
            j++;
        }
    }

    while(i<n1){
        nums3.push_back(nums1[i]);
        i++;
    }
    while(j<n2){
        nums3.push_back(nums2[j]);
        j++;
    }

    if(n%2==0){
        return (nums3[n/2 - 1]+nums3[n/2])/2.0;
        
    }else{
        return nums3[n/2];

    }
}

double optimal_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Time complexity : O(log(min(n1,n2)))
    // space complexity : O(1)

    int n1=nums1.size();
    int n2=nums2.size();

    // swap it because we are going to apply binary search on nums1
    if(n1>n2){
        return optimal_findMedianSortedArrays(nums2,nums1);
    }

    // total length
    int n=n1+n2;

    // left half
    int left=n/2;

    // apply binary search
    int low=0;
    int high=n1;  // max all element can we take 

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
            // if n is EVEN
            if(n%2==0) return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            
            // if n is ODD
            else return min(r1,r2);
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
    // vector<int>nums1={2,3,6,15};
    // vector<int>nums2={1,4,7,10,12};

    vector<int>nums1={1,2,3,4};
    vector<int>nums2={5,6,7,8,9,10};

    // 1. Brute
    cout<<brute_findMedianSortedArrays(nums1,nums2)<<endl;

    // 2. optimal
    cout<<optimal_findMedianSortedArrays(nums1,nums2)<<endl;
}