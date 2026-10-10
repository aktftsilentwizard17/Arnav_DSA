class Solution {
private:
    const vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void myfun(int index,string digits,string curr,vector<string>&result){
        if(index==digits.size()){
            result.push_back(curr);
            return;
        }
        char currdigit = digits[index];
        string currdigitletters = mapping[currdigit-'0'];
        for(char c:currdigitletters){
            curr.push_back(c);
            myfun(index+1,digits,curr,result);
            curr.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        string curr="";
        vector<string> result;
        if(digits.empty()) return result;
        myfun(0,digits,curr,result);
        return result;
    }
};