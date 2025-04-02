class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> arr(n, 0);
        long long maxVal = 0;
        long long res = 0;
        for(int i=0; i<n; i++) {
            int next = i + questions[i][1] + 1;

            maxVal = max(maxVal, arr[i]);

            if(next < n) arr[next] = max(arr[next], questions[i][0] + maxVal);
            else {
                res = max(res, questions[i][0] + maxVal);
            }
            
        }
        return max(res, arr[n-1]);
    }
};