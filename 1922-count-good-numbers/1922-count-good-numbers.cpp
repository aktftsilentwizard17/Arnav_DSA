class Solution {
private:
    const int MOD = 1e9+7;
    long long modpow(long long x,long long n){
        x=x%MOD;
        long long ans = 1;

        while(n>0){
            if(n&1){ //odd power
            ans=(ans*x)%MOD;
            }
            x=(x*x)%MOD;
            n>>=1; // same as n=n/2
        }

        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long wayseven = modpow(5,even);
        long long waysodd = modpow(4,odd);

        return (wayseven*waysodd)%MOD;
    }
};