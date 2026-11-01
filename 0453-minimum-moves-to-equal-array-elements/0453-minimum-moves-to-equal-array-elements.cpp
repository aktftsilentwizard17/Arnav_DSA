class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minnumber = *min_element(nums.begin(),nums.end());
        for(int i:nums){
            sum+=i-minnumber;
        }
        return sum;
    }
};