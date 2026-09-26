class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0||n==1) return n;

        int k = 0;
        for(int i=1;i<n;i++){
            if(nums[k]!=nums[i]){
                k++;
                nums[k]=nums[i];
            }
        }

        return k+1;
    }
};