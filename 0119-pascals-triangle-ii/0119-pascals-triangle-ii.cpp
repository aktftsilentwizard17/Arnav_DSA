class Solution {
public:
    vector<int> getRow(int idx) {
        vector<int> ans;
        int r = idx;
        long long value=1;
        for(int c=0;c<r+1;c++){
            if(c==r) value = 1;
            ans.push_back(value);
            value=value*(r-c)/(c+1);
        }
        return ans;
    }
};