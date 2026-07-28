class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> vec(26,0);
        for(char c:s){
            vec[c-'a']++;
        }
        string left="";
        string right="";
        string middle="";
        for(int i=0;i<26;i++){
            left.append(vec[i]/2,char('a'+i));
            if(vec[i]%2) middle=char('a'+i);
        }
        right=left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};