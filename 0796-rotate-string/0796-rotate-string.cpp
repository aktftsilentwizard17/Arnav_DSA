class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int k=0;
        if(s==goal) return true;
        while(k<n){
            string temp = s;
            reverse(temp.begin(),temp.end());
            reverse(temp.begin(),temp.begin()+k);
            reverse(temp.begin()+k,temp.end());
            if(temp==goal) return true;
            k++;
        }
        return false;
    }
};