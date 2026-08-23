class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> charS;
        unordered_map<char,int> charT;

        for(int i=0;i<s.size();i++){
            if(charS.find(s[i])==charS.end()){
                charS[s[i]]=i;
            }
            if(charT.find(t[i])==charT.end()){
                charT[t[i]]=i;
            }
            if (charS[s[i]] != charT[t[i]]) {
                return false;
            }
        }

        return true;
    }
};