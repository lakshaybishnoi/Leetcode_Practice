class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ind =0;
        int n = chars.size();
        while(i<n){
            char curr_char = chars[i];
            int count = 0;
            while(i<n && chars[i]==curr_char){
                count++;
                i++;

            }
            chars[ind] = curr_char;
            ind++;
            if(count>1){
            string str = to_string(count);
            
            for(char &ch:str){
                chars[ind]=ch;
                ind++;
            }
            }
        }

        
    return ind;}
};