class Solution {
private:
    bool canSplit(const vector<int>& nums, int k, long long maxSum) {
        int subarraysCount = 1;
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarraysCount++;   // Start a new subarray
                currentSum = num;
            } else {
                currentSum += num;  // Add to current subarray
            }
        }

        return subarraysCount <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;        // 'mid' works; try to find a SMALLER maximum sum
                high = mid - 1;   // Search left
            } else {
                low = mid + 1;    // 'mid' is too small; search right
            }
        }

        return ans;
    }
};