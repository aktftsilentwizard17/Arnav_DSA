class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto const&[element,frequency]:freq){
            pq.push({frequency,element});
        }

        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};