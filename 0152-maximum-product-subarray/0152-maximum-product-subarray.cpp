class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Kadane's algorithm
        int currmin = nums[0];
        int currmax = nums[0];
        int maxsofar = nums[0];

        for(int i=1;i<nums.size();i++){
            int x = nums[i];
            if(x<0){
                swap(currmin,currmax);
            }
            currmin=min(currmin,currmin*x);
            currmax=max(currmax,currmax*x);
            maxsofar=max(maxsofar,currmax);
        }

        return maxsofar;
    }
};