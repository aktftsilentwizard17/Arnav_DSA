class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxsum = INT_MIN;
        int left=0;
        
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            if(right-left+1==k){
                maxsum=max(sum,maxsum);
                sum-=nums[left];
                left++;
            }
        }

        return (double) maxsum/k;

    }
};