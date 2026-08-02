class Solution {
public:
    int search(vector<int>& nums, int target) {
        //in any rotated sorted array from pov of mid, it is always left-sorted or right-sorted
        int st = 0; int end = nums.size()-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(target==nums[mid]) return mid;
            if(nums[st]<=nums[mid]){//left sorted
                if(nums[st]<=target&&target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{//right sorted
                if(nums[mid]<=target&&target<=nums[end]){
                    st = mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};