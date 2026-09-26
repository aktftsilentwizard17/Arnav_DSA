class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> map;
        for(auto&i:knowledge){
            map[i[0]]=i[1];
        }

        string result = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                string key = "";
                i++;

                while(i<n&&s[i]!=')'){
                    key+=s[i];
                    i++;
                }

                if(map.count(key)){
                    result+=map[key];
                }
                else{
                    result+='?';
                }
            }
            else{
                result+=s[i];
            }
        }

        return result;
    }
};