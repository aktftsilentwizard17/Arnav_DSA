class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = 0;
        int evensum = 0;
        int odd = 2*n + 1;
        int even = 2*n;
        for(int i=1;i<odd;i+=2){
            oddsum+=i;
        }
        for(int i=2;i<even;i+=2){
            evensum+=i;
        }
        return gcd(oddsum,evensum);
    }
};