class Solution {
public:
    bool consecutiveSetBits(int n) {
        int paircount = 0;
        while(n>0){
            if((n&1)==1 && ((n>>1)&1)==1){
                paircount++;
            }
            n>>=1;
        }
    return paircount==1;
    }
};