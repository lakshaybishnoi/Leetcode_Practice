class Solution {
private:
    bool isPal(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
private:
    int fun(int ind,string &s,vector<int>& dp){
        int mini = 1e9;
        int n = s.length();
        if(ind==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        for(int j = ind;j<n;j++){
            if(isPal(ind,j,s)){
                int cost = 1+fun(j+1,s,dp);
                mini = min(mini,cost);
            }
           
        }
        return dp[ind] = mini;


    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return fun(0,s,dp)-1;
        
    }
};