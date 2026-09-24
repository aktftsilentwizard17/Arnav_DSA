class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        if(nums[0]==0) return 0;
        int idx = -1;

        for(int i=1;i<nums.size();i++){
            int sum = 0;
            int temp = nums[i];
            while(temp>0){
                int digit = temp%10;
                sum+=digit;
                temp/=10;
            }
            if(sum==i){
                idx=i;
                break;
            }
        }

        return idx;
    }
};