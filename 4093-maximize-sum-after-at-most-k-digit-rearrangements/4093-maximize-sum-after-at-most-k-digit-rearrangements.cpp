class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long ans = 0;
        vector<int> diff;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            string num = to_string(nums[i]);
            sort(num.rbegin(),num.rend());
            int best = stoi(num);
            diff.push_back(best-nums[i]);
        }
        sort(diff.rbegin(),diff.rend());
        for(int i=0;i<k;i++){
            ans+=diff[i];
        }
        return ans;
    }
};