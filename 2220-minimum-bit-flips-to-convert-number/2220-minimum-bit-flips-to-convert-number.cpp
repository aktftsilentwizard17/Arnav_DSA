class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xordist = start^goal;
        int dist = 0;
        while(xordist>0){ //counting number of set bits
            xordist&=(xordist-1);
            dist++;
        }
        return dist;
    }
};