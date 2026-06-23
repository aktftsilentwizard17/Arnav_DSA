class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> totalcount(26,0);
        vector<int> targetcount(26,0);

        for(char c:s){
            totalcount[c-'a']++;
        }
        for(char c:target){
            targetcount[c-'a']++;
        }

        int maxword = INT_MAX;
        for(int i=0;i<26;i++){
            if(targetcount[i]>0){
                int count = totalcount[i]/targetcount[i];
                maxword = min(maxword,count);
            }
        }
        return maxword;

    }
};