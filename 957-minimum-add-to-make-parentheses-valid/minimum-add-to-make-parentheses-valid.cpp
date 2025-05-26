class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded = 0;
        int insertions = 0;

        for (char ch : s) {
            if (ch == '(') {
                openNeeded++;
            } else {  
                if (openNeeded > 0) {
                    openNeeded--;  
                } else {
                    insertions++;   
                }
            }
        }

        return insertions + openNeeded;
    }
};
