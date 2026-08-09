class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(),nums.end());
        int longeststreak=0;
        for(int num:numset){
            //check if num is the start of a seqeunce
            if(numset.find(num-1)==numset.end()){
                int currnum = num;
                int currstreak = 1;
                while(numset.find(currnum+1)!=numset.end()){
                    currnum++;
                    currstreak++;
                }
                longeststreak = max(longeststreak,currstreak);
            }
        }
        return longeststreak;
    }
};