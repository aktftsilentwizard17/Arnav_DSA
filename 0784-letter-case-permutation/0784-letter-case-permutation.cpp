class Solution {
private:
    void myfun(int index,string s,vector<string>&res){
        if(index==s.size()){
            res.push_back(s);
            return;
        }

        if(isdigit(s[index])){
            myfun(index+1,s,res);
        }
        else{
            s[index]=tolower(s[index]);
            myfun(index+1,s,res);

            s[index]=toupper(s[index]);
            myfun(index+1,s,res);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        myfun(0,s,res);
        return res;
    }
};