class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int maxnumber = *max_element(nums.begin(),nums.end());
        for(int i:nums){
            sum+=abs(i-maxnumber);
        }
        return sum;        
    }
};