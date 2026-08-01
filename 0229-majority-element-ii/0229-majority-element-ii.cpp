class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int> ans;
        int threshold = nums.size()/3;
        for(auto i:freq){
            int element = i.first;
            int count = i.second;
            if(count>threshold){
                ans.push_back(element);
            }
        }
        return ans;
    }
};