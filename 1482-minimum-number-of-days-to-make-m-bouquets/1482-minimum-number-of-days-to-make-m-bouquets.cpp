class Solution {
private:
    bool fun(const vector<int>& bloomday, int m, int k, int mid){
        int consecflow = 0;
        int bouq = 0;
        for(int i:bloomday){
            if(i<=mid){
                consecflow++;
                if(consecflow==k){
                    bouq++;
                    consecflow=0;
                }
            }
            else{
                consecflow=0;
            }
        }
        return bouq>=m;
    }

public:
    int minDays(vector<int>& bloomday, int m, int k) {
        int n = bloomday.size();
        if((long long)m*k>n){
            return -1;
        }
        int low = *min_element(bloomday.begin(),bloomday.end());
        int high = *max_element(bloomday.begin(),bloomday.end());
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(fun(bloomday,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};