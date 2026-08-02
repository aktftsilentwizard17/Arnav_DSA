class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxval = 0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                long long a = nums[i];
                long long b = nums[j];
                long long g = gcd(a,b);
                long long temp = (a/g)*(b/g);
                maxval = max(maxval,temp);
            }
        }
        return maxval;
    }
};