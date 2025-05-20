class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26,0);
        int n = sentence.size();
        for(char &ch:sentence){
            int ind = ch-'a';
            arr[ind]++;
        }
        for(int count:arr){
            if(count==0)return false;
        }
        
    return true;}
};