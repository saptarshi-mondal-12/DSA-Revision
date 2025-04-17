#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute_smallestDivisor(vector<int>& nums, int threshold) {
    // TC=O(N^2)
    // SC=O(1)
    int n=nums.size();
    int maxi=*max_element(nums.begin(),nums.end());
    for(int i=1;i<=maxi;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(nums[j]%i==0){
                sum+=(nums[j]/i);
            }else{
                sum+=(nums[j]/i)+1;
            }
        }
        if(sum<=threshold){
            return i;
        }
    }
    return -1;
}

int possible(vector<int>& nums, int n, int mid){
    int sum=0;
    for(int i=0;i<n;i++){
        if(nums[i]%mid==0){
            sum+=(nums[i]/mid);
        }else{
            sum+=(nums[i]/mid)+1;
        }
    }
    return sum;
}

int optimal_smallestDivisor(vector<int>& nums, int threshold) {
    // TC= O(log(max(arr))) * O(n) 

    int n=nums.size();
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(possible(nums,n,mid) <= threshold){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={1,2,5,9};
    int threshold=6;

    // 1. brute
    cout<<brute_smallestDivisor(nums,threshold)<<endl;

    // 2. optimal
    cout<<optimal_smallestDivisor(nums,threshold);




}