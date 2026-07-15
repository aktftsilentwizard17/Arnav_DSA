class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while(left<=right){
            long long sqsum = left*left + right*right;
            if(sqsum==c){
                return true;
            }
            else if(sqsum<c){
                left++;
            }
            else{
                right--;
            }
        }

        return false;
    }
};