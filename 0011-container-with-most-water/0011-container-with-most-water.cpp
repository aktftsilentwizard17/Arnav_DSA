class Solution {
public:
    int maxArea(vector<int>& height) {
        //as two heights being condidered, use two pointer approach (kadane's)
        int maxwater=0;
        int lp=0,rp=height.size()-1;

        while(lp<rp){
            int w = rp-lp;
            int h = min(height[lp],height[rp]);
            int currentwater = w*h;
            maxwater=max(maxwater,currentwater);

            height[lp]<height[rp] ? lp++ : rp--;
        }

        return maxwater;
    }
};