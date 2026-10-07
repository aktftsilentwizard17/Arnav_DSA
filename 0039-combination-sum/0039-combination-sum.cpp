class Solution {
private:
    void myfun(int start,int target,vector<int>&candidates,vector<int>&curr,vector<vector<int>>&res){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<0) return;
        for(int i=start;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            myfun(i,target-candidates[i],candidates,curr,res);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        myfun(0,target,candidates,curr,res);
        return res;
    }
};