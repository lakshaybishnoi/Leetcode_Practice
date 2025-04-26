class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto it:mp){
            minH.push({it.second,it.first});
            if(minH.size()>k){
                minH.pop();
            }
        }
        vector<int> ans;
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        
    return ans;}
};