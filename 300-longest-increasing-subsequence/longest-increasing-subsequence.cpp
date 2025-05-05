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
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i =n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int notTake = dp[i+1][j+1];
                int take =0;
                if(j==-1 || nums[i]>nums[j]){
                    take += 1+ dp[i+1][i+1];
                }
                dp[i][j+1]= max(take,notTake);
            }
        }
        
    return dp[0][0];}
};