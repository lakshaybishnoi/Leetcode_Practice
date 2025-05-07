class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto n = nums.size();
        vector<int> dp(n,1);
        auto maxi =1;
        for(auto i=0;i<n;i++){
            for(auto prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i] = max(1+dp[prev],dp[i]);
                }
               
             maxi = max(maxi,dp[i]);}
        }
    return maxi;}
};