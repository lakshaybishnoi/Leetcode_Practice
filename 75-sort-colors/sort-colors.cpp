class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j = n-1;
        int it=0;
        while(it<=j){
            if(nums[it]==0){
                swap(nums[it],nums[i]);
                it++;
                i++;
            }else if(nums[it]==2){
                swap(nums[it],nums[j]);
                j--;
                
            }else{
                it++;
            }
        }
        
        
    }
};