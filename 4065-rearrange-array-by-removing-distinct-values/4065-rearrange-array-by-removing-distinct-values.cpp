class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101,0);
        int maxfreq = -1;
        for(int i:nums){
            freq[i]++;
            maxfreq=max(maxfreq,freq[i]);
        }
        vector<int> ans;
        for(int round=0;round<maxfreq;round++){
            for(int i=1;i<=100;i++){
                if(freq[i]>0){
                    ans.push_back(i);
                    freq[i]--;
                }
            }
        }
        return ans;
    }
};