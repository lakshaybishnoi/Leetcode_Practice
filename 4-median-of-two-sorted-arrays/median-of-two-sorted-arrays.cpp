#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n = nums1.size();
        int m = nums2.size();
        int i =0,j=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }else{
                res.push_back(nums2[j]);
                j++;

            }
        }
        while(i<n)res.push_back(nums1[i++]);
        while(j<m)res.push_back(nums2[j++]);
    int k = res.size();
    if (k % 2 == 1) {
        return res[k / 2];
    } else {
        return (res[k / 2 - 1] + res[k / 2]) / 2.0;
    }
    return -1;

    }
};