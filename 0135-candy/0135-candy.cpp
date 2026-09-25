class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);

        //left neighbour
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
        }

        //right neghbour
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) candies[i]=max(candies[i],candies[i+1]+1);
        }

        int candy = 0;
        for(int c:candies){
            candy+=c;
        }

        return candy;
    }
};