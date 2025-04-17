#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int brute_trappingRainwater(int arr[], int n){
    // Time complexity = O(n) 
    // space complexity = O(2n)

    int left[n],right[n];

    // finding left maximum for every index
    left[0]=arr[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }


    // finding right maximum for every index
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }

    // calculating min(leftmax-rightmax)- index
    int ans=0;
    for(int i=0;i<n;i++){
        // arr[i]= total capacity it can hold total me se kitna hold kr sakte ho 

        ans+=min(left[i],right[i]) - arr[i];
    }

    return ans;
}



int optimal_trappingRainwater(int height[], int n){
    // Time complexity = O(n) 
    // space complexity = O(1)
    
    int left=0, right=n-1;
    
    int res=0;

    int maxleft=0, maxright=0;

    while(left<=right){
        if(height[left]<=height[right]){
            if (height[left]>=maxleft){
                maxleft=height[left];
            }
            else{
                res+=maxleft-height[left];
            }
            left++;
        }
        else{
            if (height[right]>=maxright){
                maxright=height[right];
            }
            else{
                res+=maxright-height[right];
            }
            right--;
        }
    }
    return res;
}

int main(){
    int n=8;
    int arr[n]={3,1,2,4,0,1,3,2};

    // brute
    cout<<brute_trappingRainwater(arr,n)<<endl;

    // optimal
    cout<<optimal_trappingRainwater(arr,n)<<endl;
}