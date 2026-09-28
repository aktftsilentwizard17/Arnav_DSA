class Solution {
private:
    bool fun(const vector<int>& weights,int days, int capacity){
        int currcap = 0;
        int reqdays = 1;
        for(int i:weights){
            if(currcap+i>capacity){
                reqdays++;
                currcap=i;
            }
            else{
                currcap+=i;
            }
        }
        return reqdays<=days;
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