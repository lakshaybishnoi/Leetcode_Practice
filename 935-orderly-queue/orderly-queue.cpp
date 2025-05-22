class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        
        if(k == 1){
            string smallest = s;
            for(int i = 0; i < n; ++i){
                s = s.substr(1) + s[0];        
                smallest = min(smallest, s);   
            }
            return smallest;
        } else {
            sort(s.begin(), s.end());         
            return s;
        }
    }
};
