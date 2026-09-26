class Solution {
public:
    string decodeString(string s) {
        // As brackets can be nested, stack use is compulsory

        stack<int> countstack;
        stack<string> stringstack;
        string currstr = "";
        int k = 0;
        for(char c:s){
            if(isdigit(c)){
                k=k*10+(c-'0'); // for multidigit numbers
            }
            else if(c=='['){
                countstack.push(k);
                stringstack.push(currstr);
                // reset for inner nested if any
                k = 0;
                currstr = "";
            }
            else if(c==']'){
                int reptimes = countstack.top(); countstack.pop();
                string decoded = stringstack.top(); stringstack.pop();
                for(int i=0;i<reptimes;i++){
                    decoded+=currstr;
                }
                currstr=decoded;
            }
            else{
                currstr+=c;
            }
        }

        return currstr;
    }
};