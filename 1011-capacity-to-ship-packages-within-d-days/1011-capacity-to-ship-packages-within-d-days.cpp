class Solution {
public:
    int canShip(vector<int>&weights,int days,int capacity){
        int daysneeded = 1;
        int currweight = 0;
        for(int weight:weights){
            if(currweight+weight>capacity){
                daysneeded++;
                currweight=weight;
            }
            else{
                currweight+=weight;
            }
        }
        return daysneeded<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        for(int i:weights){
            low=max(low,i);
            high+=i;
        }
        while(low<high){
            int mid = low+(high-low)/2;
            if(canShip(weights,days,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};