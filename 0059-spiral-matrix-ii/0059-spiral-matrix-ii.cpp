class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int srow=0,erow=n-1,scol=0,ecol=n-1;
        int j=1;
        if(n==1) return {{1}};
        if(n==2) return {{1,2},{4,3}};

        while(srow <= erow && scol <= ecol){
            //top
            for(int i=scol;i<=ecol;i++){
                matrix[srow][i]=j;
                j++;
            }
            //right
            for(int i=srow+1;i<=erow;i++){
                matrix[i][ecol]=j;
                j++;
            }
            //bottom
            for(int i=ecol-1;i>=scol;i--){
                if(srow==erow) break;
                matrix[erow][i]=j;
                j++;
            }
            //left
            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol) break;
                matrix[i][scol]=j;
                j++;
            }
            srow++;erow--;scol++;ecol--;
        }
        return matrix;
    }
};