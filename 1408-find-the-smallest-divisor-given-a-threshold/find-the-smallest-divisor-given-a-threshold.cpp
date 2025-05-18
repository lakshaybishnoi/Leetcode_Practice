class Solution {
public:
    int fun(vector<int>& nums,int x){
        int sum =0;
        for (int num : nums) {
            sum += ceil((double)num / (double)x);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = *max_element(nums.begin(), nums.end());
        int ans =-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int x = fun(nums,mid);
            if(x<=threshold){
                high = mid-1;
                ans =mid;
            }else{
                low = mid+1;
            }
        }
        
    return ans;}
};