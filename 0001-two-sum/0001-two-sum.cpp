class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vec(n); //sorting changes origial indices, hence store them

        for (int i = 0; i < n; ++i) {
            vec[i] = {nums[i], i};
        }

        sort(vec.begin(), vec.end());

        int i = 0, j = n - 1;
        while (i < j) {
            int pairsum = vec[i].first + vec[j].first;

            if (pairsum < target) {
                i++;
            } else if (pairsum > target) {
                j--;
            } else {
                return {vec[i].second, vec[j].second}; // Return stored original indices
            }
        }

        return {};
    }
};