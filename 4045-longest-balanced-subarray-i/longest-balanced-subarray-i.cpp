constexpr int N=1e5+1;
bitset<N> seen=0;
class Solution {
public:
    static int longestBalanced(vector<int>& nums) {
        const int n=nums.size();
        int len=0;
        for(int l=0; l<n; l++){
            if (l>n-len) break; 
            int diff=0;
            for(int r=l; r<n; r++){
                const int x=nums[r];
                if (!seen[x]) {diff+=(1-(x&1)*2), seen[x]=1; }
                if (diff==0)
                    len=max(len, r-l+1);
            }
            for(int i=l; i<n; i++) seen[nums[i]]=0;
        }
        return len;
    }
};