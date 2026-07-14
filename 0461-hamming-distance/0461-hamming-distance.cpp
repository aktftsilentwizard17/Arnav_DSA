class Solution {
public:
    int hammingDistance(int x, int y) {
        int xordist = x^y;
        int dist = 0;
        while(xordist>0){
            xordist&=(xordist-1);
            dist++;
        }
        return dist;
    }
};