class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        long long sum = 0, maxi = 0;
        unordered_map<int, int> freq;

        while (j < nums.size()) {
            sum += nums[j];
            freq[nums[j]]++;

            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {

                if (freq.size() == k) {
                    maxi = max(maxi, sum);
                }

                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                sum -= nums[i];
                i++;
                j++;
            }
        }

        return maxi;
    }
};
