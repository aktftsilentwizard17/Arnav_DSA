class Solution {
public:
    int firstStableIndex(vector<int>& nums, int m) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            int maxint = INT_MIN;
            int minint = INT_MAX;
            int j = 0;
            int k = i;
            while(j<=i){
                maxint=max(maxint,nums[j]);
                j++;
            }
            while(k<=n-1){
                minint=min(minint,nums[k]);
                k++;
            }
            if(maxint-minint<=m) return i;
        }

        return -1;
    }
};