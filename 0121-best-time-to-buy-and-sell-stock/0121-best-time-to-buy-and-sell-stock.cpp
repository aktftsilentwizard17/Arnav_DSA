class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //tweak of Kadane's Algorithm
        int minprice = prices[0];
        int maxprofit = 0;
        for(int i=1;i<prices.size();i++){
            if(minprice>prices[i]){
                minprice=prices[i];
            }
            else{
                maxprofit=max(maxprofit,prices[i]-minprice);
            }
        }
        return maxprofit;
    }
};