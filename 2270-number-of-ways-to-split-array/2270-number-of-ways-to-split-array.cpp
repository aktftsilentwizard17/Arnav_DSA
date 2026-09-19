class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalsum = accumulate(nums.begin(),nums.end(),0LL);
        long long leftsum=0;
        int count = 0;
        for(int i=0;i<n-1;i++){
            leftsum+=nums[i];
            long long rightsum = totalsum-leftsum;
            if(leftsum>=rightsum){
                count++;
            }
        }
        return count;
    }
};