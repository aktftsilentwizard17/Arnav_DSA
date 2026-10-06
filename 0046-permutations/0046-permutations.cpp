class Solution {
private:
    void myfun(vector<int>&nums,vector<int>&curr,vector<bool>&visited,vector<vector<int>>&result){
        //base case
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }

        //choices-all elements in nums
        for(int i=0;i<nums.size();i++){
            //constraint
            if(visited[i]) continue;

            //make choice
            visited[i]=true;
            curr.push_back(nums[i]);
            myfun(nums,curr,visited,result);

            //backtrack
            curr.pop_back();
            visited[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> visited(nums.size(),false); //for handling contraint of avoid duplicates

        myfun(nums,curr,visited,result);

        return result;
    }
};