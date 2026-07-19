class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int n = min(word1.size(),word2.size());

        for(int i=0;i<n;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if(word1.size()<word2.size()){
            ans.append(word2.substr(n));
        }
        else if (word1.size()>word2.size()){
            ans.append(word1.substr(n));
        }

        return ans;
    }
};