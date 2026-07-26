class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int srow=0,erow=m-1,scol=0,ecol=n-1;
        vector<int> ans;
        //corner case included to break out of one of side loops for odd size matrices, so that each overlapping boundary points at same elements

        while(srow<=erow&&scol<=ecol){
            //top
            for(int i=scol;i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
            }
            //right
            for(int i=srow+1;i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
            }
            //bottom
            for(int i=ecol-1;i>=scol;i--){
                if(srow==erow) break;
                ans.push_back(matrix[erow][i]);
            }
            //left
            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol) break;
                ans.push_back(matrix[i][scol]);
            }
            srow++;erow--;scol++;ecol--;
        }

        return ans;

    }
};