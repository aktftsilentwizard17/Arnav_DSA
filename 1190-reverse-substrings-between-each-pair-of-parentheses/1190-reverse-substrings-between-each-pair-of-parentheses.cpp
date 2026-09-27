class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;
        for(char c:s){
            if(c==')'){
                string temp = "";
                while(!st.empty()&&st.back()!='('){
                    temp+=st.back();
                    st.pop_back();
                }
                // pop the extra '('
                if(!st.empty()) st.pop_back();
                // push reversed again onto stack for nested
                for(char i:temp){
                    st.push_back(i);
                }
            }
            else st.push_back(c);
        }
        return string(st.begin(),st.end());
    }
};