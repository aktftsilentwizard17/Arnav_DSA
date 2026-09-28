class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0; // Minimum possible open parentheses
        int cmax = 0; // Maximum possible open parentheses
        
        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else if (c == '*') {
                cmin--; // Greedily assume it acts as ')' or ""
                cmax++; // Greedily assume it acts as '('
            }
            
            // If max possible open brackets is negative, we have too many ')'
            if (cmax < 0) return false;
            
            // cmin shouldn't go below 0 because we can't have "negative" required open brackets
            if (cmin < 0) cmin = 0;
        }
        
        // If 0 is within our range of possible open brackets, the string is valid
        return cmin == 0;
    }
};
