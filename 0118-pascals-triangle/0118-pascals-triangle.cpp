class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> ans(rows);
        for(int r=0;r<rows;r++){
            int value = 1;
            for(int c=0;c<r+1;c++){
                if(c==r) value=1;
                ans[r].push_back(value);
                value=value*(r-c)/(c+1);
            }
        }
        return ans;
    }
};