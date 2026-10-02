class Solution {
public:
    int divisorSubstrings(int num, int k) {
        //size of sliding window is given by (right-left+1)
        int count=0;
        int left=0;
        string s = to_string(num);

        for(int right=0;right<s.size();right++){
            if(right-left+1==k){
                string temp = s.substr(left,k);
                int x = stoi(temp);
                if(x!=0&&num%x==0) count++;
                left++;
            }
        }

        return count;

    }
};