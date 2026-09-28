class Solution {
public:
    int maxDepth(string s) {
        int count = 1;
        int maxcnt=-1;
    
        for(char c:s){
            if(c=='(') count++;
            maxcnt=max(count-1,maxcnt);
            if(c==')') count--;
        }
        return maxcnt;
    }
};