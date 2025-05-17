class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int th = n/3;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto &pair:mp){
            if(pair.second>th){
                ans.push_back(pair.first);
            }
        }
    return ans;}
};