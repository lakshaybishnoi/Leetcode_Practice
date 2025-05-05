class Solution {
public:
    int fun(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp){
        int n = nums.size();
        if(ind == n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int notTake = fun(ind+1,prev,nums,dp);
        int take =0;
        if(prev==-1 ||nums[ind]>nums[prev] ){
            take += 1+fun(ind+1,ind,nums,dp); 
        }
        return dp[ind][prev+1]= max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int ans = fun(0,-1,nums,dp);
        return ans;
        
    }
};