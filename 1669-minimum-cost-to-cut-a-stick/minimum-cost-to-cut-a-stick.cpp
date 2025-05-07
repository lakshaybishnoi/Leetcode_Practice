class Solution {
private:
    int fun(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = INT_MAX;
        for(int ind =i;ind<=j;ind++){
            int cost = cuts[j+1]-cuts[i-1]+fun(i,ind-1,cuts,dp)+fun(ind+1,j,cuts,dp);
        mini = min(mini,cost);}
        
        return dp[i][j]= mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);int c = cuts.size();
        vector<vector<int>> dp(c,vector<int>(c,-1));
        sort(cuts.begin(),cuts.end());
        return fun(1,c-2,cuts,dp);
        
    }
};