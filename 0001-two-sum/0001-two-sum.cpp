class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // two solutions, using two pointer and using hash map

        //two pointers, requires sorting
        // int n = nums.size();
        // vector<pair<int, int>> vec(n); //sorting changes origial indices, hence store them

        // for (int i = 0; i < n; ++i) {
        //     vec[i] = {nums[i], i};
        // }

        // sort(vec.begin(), vec.end());

        // int i = 0, j = n - 1;
        // while (i < j) {
        //     int pairsum = vec[i].first + vec[j].first;

        //     if (pairsum < target) {
        //         i++;
        //     } else if (pairsum > target) {
        //         j--;
        //     } else {
        //         return {vec[i].second, vec[j].second}; // Return stored original indices
        //     }
        // }

        // return {};

        //------------------------------------------------------------------------------

        // Optimized hash map solution
        int n = nums.size();
        unordered_map<int, int> count;
        count.reserve(n); // Pre-allocate buckets to prevent rehashing

        for (int i = 0; i < n; ++i) {
            int needed = target - nums[i];
            auto it = count.find(needed); // Single lookup
            if (it != count.end()) {
                return {it->second, i};
            }
            count[nums[i]] = i;
        }

        return {};
    }
};