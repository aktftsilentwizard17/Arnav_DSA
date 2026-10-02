class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whitecount=0;
        int mincount = INT_MAX;
        int left=0;
        for(int right=0;right<blocks.size();right++){
            if(blocks[right]=='W') whitecount++;
            if(right-left+1==k){
                mincount=min(whitecount,mincount);
                
                //slide forward by decreasing whitecount
                if(blocks[left]=='W') whitecount--;
                left++;
            }
        }
        return mincount;
    }
};