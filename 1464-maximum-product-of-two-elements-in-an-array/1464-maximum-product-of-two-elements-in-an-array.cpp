class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int first=0;
        int second=0;

        if(n==2) return (nums[0]-1)*(nums[1]-1);

        for(int i:nums){
            if(i>=first){
                second=first;
                first=i;
            }
            else if(i>=second){
                second=i;
            }
        }

        return (first-1)*(second-1);
    }
};