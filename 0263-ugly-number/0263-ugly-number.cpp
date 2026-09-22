class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        int factors[] = {2,3,5};
        for(int i:factors){
            while(n%i==0){
                n=n/i;
            }
        }
        return n==1;
    }
};