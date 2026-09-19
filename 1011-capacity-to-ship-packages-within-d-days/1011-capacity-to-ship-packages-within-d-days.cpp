class Solution {
private:
    bool fun(const vector<int>& weights,int days, int capacity){
        int currweight = 0;
        int totaldays = 1;
        for(int w:weights){
            if(currweight+w>capacity){
                totaldays++;
                currweight=w;
            }
            else{
                currweight+=w;
            }
        }
        return totaldays<=days;
    }
public:
    int shipWithinDays(vector<int>&weights,int days){
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(fun(weights,days,mid)){
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