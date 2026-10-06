class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="") return 0;
        int open=0,add=0;
        for(char c:s){
            if(c=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else{
                    add++;
                }
            }
        }
        return add+open;

    }
};