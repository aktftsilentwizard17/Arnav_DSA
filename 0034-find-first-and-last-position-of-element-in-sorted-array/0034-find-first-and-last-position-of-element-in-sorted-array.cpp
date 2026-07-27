class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int low=0; int high=nums.size()-1;
        int start=-1;

        //first target
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                start=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        //second target
        low=0;high=nums.size()-1;
        int end=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                end=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        ans={start,end};
        return ans;
    }
};