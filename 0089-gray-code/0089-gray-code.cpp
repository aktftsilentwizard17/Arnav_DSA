class Solution {
private:
    bool myfun(int n,int totalnodes,vector<bool>&visited,vector<int>&result){
        if(result.size()==totalnodes){
            //check for first and last element
            int diff = result.front()^result.back();
            return (diff&(diff-1))==0;
        }
        int lastnum=result.back();
        for(int i=0;i<n;i++){
            int nextnum=lastnum^(1<<i);
            if(!visited[nextnum]){
                visited[nextnum]=true;
                result.push_back(nextnum);
                if(myfun(n,totalnodes,visited,result)) return true;
                visited[nextnum]=false;
                result.pop_back();
            }
        }
        return false;
    }
public:
    vector<int> grayCode(int n) {
        int totalnodes=(1<<n);
        vector<bool> visited(totalnodes,false);
        vector<int> result;
        visited[0]=true;
        result.push_back(0);
        myfun(n,totalnodes,visited,result);
        return result;
    }
};