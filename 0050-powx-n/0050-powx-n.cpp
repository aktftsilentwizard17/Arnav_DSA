class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(x==0) return 0.0;
        if(x==-1 && n%2==0) return 1.0;
        if(x==-1 && n%2!=0) return -1.0;

        long long pow = n;
        if(pow<0){
            x=1/x;
            pow=-pow;
        }

        double ans = 1;

        while(pow>0){
            if(pow%2==1){
                ans*=x;
            }
            x*=x;
            pow/=2;
        }
        
        return ans;
    }
};