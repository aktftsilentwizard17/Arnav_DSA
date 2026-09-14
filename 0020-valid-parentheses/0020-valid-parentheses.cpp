class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c:s){
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else{
                if (st.empty()) return false;
                char topelement = st.top();
                if ((c == ')' && topelement == '(') ||
                    (c == '}' && topelement == '{') ||
                    (c == ']' && topelement == '[')) {
                    st.pop(); 
                } 
                else {
                    return false; 
                }
            }
        }

        return st.empty();
    }
};