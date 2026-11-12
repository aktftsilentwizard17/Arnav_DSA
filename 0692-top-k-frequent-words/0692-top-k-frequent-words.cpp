class Solution {
public:
    // Custom comparator structure
    struct MyComp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqmap;
        for (const string& s : words) {
            freqmap[s]++;
        }
        
        // Pass our custom comparator to the priority queue
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> maxheap;
        
        for (auto const& [str, frequency] : freqmap) {
            maxheap.push({frequency, str});
        }
        
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        
        return ans;
    }
};
