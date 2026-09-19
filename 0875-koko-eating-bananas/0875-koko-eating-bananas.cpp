class Solution {
private:
    bool canfinish(const vector<int> piles, int h, int k){
        long long hoursneeded = 0;
        for(int p:piles){
            hoursneeded+=ceil((double)p/k);
        }
        return hoursneeded<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // using binary search, find the rate k, with minimum being 1 and max being maximum element in piles
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canfinish(piles,h,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};