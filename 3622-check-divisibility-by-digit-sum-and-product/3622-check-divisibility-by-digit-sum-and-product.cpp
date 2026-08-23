class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;
        int digit;
        while(temp>0){
            digit=temp%10;
            sum+=digit;
            prod*=digit;
            temp/=10;
        }
        int divisor = sum + prod;
        if (divisor == 0) return false; // Prevent division by zero
        
        return (n % divisor == 0);
    }
};