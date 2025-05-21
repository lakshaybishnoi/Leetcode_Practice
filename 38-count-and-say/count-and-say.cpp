class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string res = "";
        string say = countAndSay(n-1);
        for(int i =0;i<say.length();i++){
            char curr_char = say[i];
            int count = 1;
            while(i<say.length()&& say[i]==say[i+1]){
                count++;
                i++;

            }
            res  += to_string(count)+ curr_char;
        }
        
    return res ;}
};