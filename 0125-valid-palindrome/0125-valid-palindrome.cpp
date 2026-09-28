class Solution {
public:
    bool isPalindrome(string s) {
        //two pointer approach, as we have to avoid everything except alnum
        int i=0;
        int j=s.length()-1;

        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};