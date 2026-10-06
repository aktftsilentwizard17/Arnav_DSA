class Solution {
private:
    void myfun(int start,int n,int k,vector<int>&curr,vector<vector<int>>&result){
        if(curr.size()==k){
            result.push_back(curr);
            return;
        }
        //pruning
        for(int i=start;i<=n-(k-curr.size())+1;i++){
            curr.push_back(i);
            myfun(i+1,n,k,curr,result);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        // we avoid the contraint of (1,2) and (2,1) by passing i+1 to the recursive call
        // for a size k, we use optimisation technique called pruning

        vector<vector<int>> result;
        vector<int> curr;
        myfun(1,n,k,curr,result);
        return result;
    }
};