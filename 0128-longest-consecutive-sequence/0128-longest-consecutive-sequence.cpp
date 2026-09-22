class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int currentlen = 1;
        int longestlen = 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    currentlen++;
                }
                else{
                    longestlen=max(currentlen,longestlen);
                    currentlen=1;
                }
            }
        }
        return max(currentlen,longestlen);
    }
};