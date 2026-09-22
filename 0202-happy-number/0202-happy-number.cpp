class Solution {
private:
    int getnext(int n){
        int result = 0;
        while(n>0){
            int digit = n%10;
            result+=digit*digit;
            n/=10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen; //for checking cycle, can also use slow-fast pointer instead
        while(seen.find(n)==seen.end()){
            seen.insert(n);
            n=getnext(n);
            if(n==1) return true;
        }
        return false;
    }
};