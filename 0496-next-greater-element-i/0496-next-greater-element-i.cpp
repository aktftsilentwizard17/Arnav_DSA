class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> s;

        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty()&&s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()) map[nums2[i]]=-1;
            else map[nums2[i]]=s.top();
            s.push(nums2[i]);
        }

        vector<int> ans;
        for(int i:nums1){
            ans.push_back(map[i]);
        }
        return ans;
    }
};