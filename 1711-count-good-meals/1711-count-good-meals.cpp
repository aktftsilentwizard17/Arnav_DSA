class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int,int> count;
        int MOD = 1e9+7;
        long long ans = 0;

        for(int x:nums){
            for(int i=0;i<=21;i++){
                int target = 1<<i; //2^i, using left shift
                int needed = target - x;
                if(count.count(needed)){
                    ans=(ans+count[needed])%MOD;
                }
            }
            count[x]++;
        }

        return ans;
    }
};