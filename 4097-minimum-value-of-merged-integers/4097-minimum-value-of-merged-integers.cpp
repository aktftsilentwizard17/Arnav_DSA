class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        vector<int> tocompare;
        for(int i=0;i<nums.size()-1;i=i+2){
            string temp = to_string(nums[i])+to_string(nums[i+1]);
            tocompare.push_back(stoi(temp));
        }
        return *min_element(tocompare.begin(),tocompare.end());
    }
};