class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss>>word){
            words.push_back(word);
        }
        if(pattern.size()!=words.size()) return false;
        unordered_map<char,int> map1;
        unordered_map<string,int> map2;
        for(int i=0;i<pattern.size();i++){
            if(map1.find(pattern[i])==map1.end()){
                map1[pattern[i]]=i+1;
            }
            if(map2.find(words[i])==map2.end()){
                map2[words[i]]=i+1;
            }
            if(map1[pattern[i]]!=map2[words[i]]){
                return false;
            }
        }
        return true;
    }
};