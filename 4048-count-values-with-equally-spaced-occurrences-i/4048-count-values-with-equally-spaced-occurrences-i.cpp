class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> pos_map;
        
        //Store all index positions for each number in 1 pass
        for (int i = 0; i < nums.size(); ++i) {
            pos_map[nums[i]].push_back(i);
        }

        int count = 0;

        for (auto& [val, indices] : pos_map) {
            if (indices.size() == 3) {
                if (indices[2] - indices[1] == indices[1] - indices[0]) {
                    count++;
                }
            }
        }

        return count;
    }
};