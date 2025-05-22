class Solution {

public:
    bool isVowel(char s){
        return(s=='a'||s=='i'||s=='e'||s=='o'||s=='u'
        ||s=='A'||s=='I'||s=='E'||s=='O'||s=='U');
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = n/2;
        int i =0;
        int j =mid;
        int countL=0;
        int countR =0;
        while(i<mid &&j<n){
            if(isVowel(s[i]))countL++;
            if(isVowel(s[j]))countR++;
            i++;
            j++;
        }
        
    return countL==countR;}
};