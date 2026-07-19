class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixgcd(nums.size());
        int mx = 0;
        long long gcdsum = 0;

        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            prefixgcd[i] = gcd(mx,nums[i]);
        }

        sort(prefixgcd.begin(),prefixgcd.end(),greater<int>());
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            gcdsum+=gcd(prefixgcd[i],prefixgcd[j]);
            i++;
            j--;
        }

        return gcdsum;
    }
};