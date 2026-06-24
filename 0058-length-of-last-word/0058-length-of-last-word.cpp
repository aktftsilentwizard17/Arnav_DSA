class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;

        int len = s.size();
        int count=0;
        for(int i=len;i>=0;i--){
            if((s[i]>64 &&s[i]<91) ||(s[i]>96 && s[i]<123)){
                count++;
            }
            else if(count>0){
                break;
            }
        }
        return count;
    }
};