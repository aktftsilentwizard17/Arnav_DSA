class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool> result(candies.size(),false);
        auto max_it = max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if((candies[i]+extra) >= *max_it){
                result[i]=true;
            }
        }
        return result;
    }
};