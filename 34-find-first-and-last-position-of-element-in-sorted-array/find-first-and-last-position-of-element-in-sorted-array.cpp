class Solution {
private:
    int lb(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high =n-1;
        int ans= n;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }return ans;
    }
private:
    int ub(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high =n-1;
        int ans= n;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int a = lb(nums,target);
        int b = ub(nums,target)-1;
        if(a>=nums.size()||nums[a]!=target)return {-1,-1};
        return {a,b};
        
    }
};