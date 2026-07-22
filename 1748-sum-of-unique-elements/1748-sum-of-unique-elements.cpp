class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> dp;
        int uniqsum = 0;
        for(int i:nums){
            dp[i]++;
        }
        for(int i:nums){
            if (dp[i]==1){
                uniqsum+=i;
            }
        }
        return uniqsum;
    }
};