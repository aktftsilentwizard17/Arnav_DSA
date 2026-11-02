class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //nth_element partially sorts a range so that the element at the nth position is exactly the element that would be there if the entire container were completely sorted, faster than complete sorting

        int n = nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int median = nums[n/2];     
        int sum = 0;
        for(int i:nums){
            sum+=abs(i-median);
        }
        return sum;
    }
};