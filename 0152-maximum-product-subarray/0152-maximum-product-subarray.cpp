class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //kadane's algo
        int maxsofar = nums[0];
        int currmax = nums[0];
        int currmin = nums[0];

        for(int i=1;i<nums.size();i++){
            int x = nums[i];
            if(x<0){
                swap(currmax,currmin);
            }
            currmax=max(x,currmax*x);
            currmin=min(x,currmin*x);
            maxsofar=max(maxsofar,currmax);
        }

        return maxsofar;
    }
};