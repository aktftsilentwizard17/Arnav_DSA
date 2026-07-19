class Solution {
public:
    int titleToNumber(string title) {
        long long result = 0;

        for(char c:title){
            int value = c - 'A' + 1;
            result = result*26 + value;
        }

        return static_cast<int>(result);
    }
};