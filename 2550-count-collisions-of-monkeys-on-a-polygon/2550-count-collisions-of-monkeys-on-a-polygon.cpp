class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int monkeyMove(int n) {
        long long mod = 1e9 + 7;
        // Calculate (2^n - 2) mod 10^9 + 7
        long long ans = (power(2, n) - 2 + mod) % mod;
        return (int)ans;
    }
};