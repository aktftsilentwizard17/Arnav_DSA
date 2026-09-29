class Solution {
public:
    int maxArea(vector<int>& height) {
        //as two heights being condidered, use two pointer approach (kadane's)
        int maxwater=0;
        int i=0,j=height.size()-1;

        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int currwater=w*h;
            maxwater=max(maxwater,currwater);

            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxwater;
    }
};