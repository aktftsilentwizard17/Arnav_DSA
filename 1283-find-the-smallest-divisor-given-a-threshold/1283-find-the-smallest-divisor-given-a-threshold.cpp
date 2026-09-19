class Solution {
private:
    bool fun(const vector<int>& nums, int threshold, int mid){
        int temp = 0;
        for(int i:nums){
            temp+=ceil((double)i/mid);
        }
        return temp<=threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int ans = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            if(fun(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};