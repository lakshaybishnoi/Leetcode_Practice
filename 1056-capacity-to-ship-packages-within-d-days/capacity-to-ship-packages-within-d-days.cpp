class Solution {
public:
    int fun(vector<int>& weights, int cap){
        int n = weights.size();
        int load =0;
        int day =1;
        for(auto& w:weights){
            if(load+w>cap){
                day++;
                load =0;
            }load+=w;
        }
        return day;

    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans =0;
        while(low<=high){
            int mid = low+(high-low)/2;
            int x = fun(weights,mid);
            if(x<=days){
                ans = mid;
                high = mid-1;

            }else{
                low =mid+1;
            }
        }
    return ans;}
};