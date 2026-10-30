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
            while(!q.empty()&&map[s[q.front()]]>1){
                q.pop();
            }
        }

        if(!q.empty()) return q.front();
        return -1;
    }
};