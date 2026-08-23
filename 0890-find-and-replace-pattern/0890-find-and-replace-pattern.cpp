class Solution {
private:
    bool matches(const string& word, const string& pattern) {
        if (word.size() != pattern.size()) return false;

        unordered_map<char, int> charW;
        unordered_map<char, int> charP;

        for (int i = 0; i < word.size(); i++) {
            // Record first-seen 1-based index
            if (charW.find(word[i]) == charW.end()) {
                charW[word[i]] = i + 1;
            }
            if (charP.find(pattern[i]) == charP.end()) {
                charP[pattern[i]] = i + 1;
            }

            // Check if first-seen positions align
            if (charW[word[i]] != charP[pattern[i]]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (const string& word : words) {
            if (matches(word, pattern)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};