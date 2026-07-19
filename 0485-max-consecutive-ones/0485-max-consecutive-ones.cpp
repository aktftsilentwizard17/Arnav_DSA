class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currct = 0;
        int maxct = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currct++;
                maxct=max(maxct,currct);
            }
            else{
                currct=0;
            }
        }

        return maxct;
    }
};