class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        queue<int> q; // we have to store index

        for(int i=0;i<s.size();i++){
            if(!map.count(s[i])){
                q.push(i);
            }
            map[s[i]]++;
            while(q.size()>0&&map[s[q.front()]]>1){
                q.pop();
            }
        }

        return q.empty()?-1:q.front();
    }
};