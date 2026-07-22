class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        int flag=0;

        while(mat!=target){
            if(flag>3) return false;
            for(int i=0;i<m;i++){
                for(int j=i+1;j<n;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<m;i++){
                reverse(mat[i].begin(),mat[i].end());
            }
            flag++;
        }

        return true;
    }
};