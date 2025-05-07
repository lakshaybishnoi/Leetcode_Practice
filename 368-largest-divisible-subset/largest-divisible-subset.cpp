class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxLen =1;
        int lastIndex = 0;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        for(int  i=0;i<n;i++){
            hash[i]=i;
            for(int prev =0;prev<i;prev++){
                if(nums[i]%nums[prev]==0&& dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;

                }
            }
            if(dp[i]>maxLen){
                maxLen = dp[i];
                lastIndex =i;
            }
        }
        vector<int> lis;
        lis.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        reverse(lis.begin(),lis.end());
        return lis;
        
    }
};