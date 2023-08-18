class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> dp;
        
        return backtrack(s, 0, wordSet, dp);
    }
    
    vector<string> backtrack(string& s, int start, unordered_set<string>& wordSet, unordered_map<int, vector<string>>& dp) {
        if (dp.find(start) != dp.end()) {
            return dp[start];
        }
        
        vector<string> result;
        if (start == s.length()) {
            result.push_back("");
            return result;
        }
        
        for (int end = start + 1; end <= s.length(); ++end) {
            string prefix = s.substr(start, end - start);
            if (wordSet.find(prefix) != wordSet.end()) {
                vector<string> suffixes = backtrack(s, end, wordSet, dp);
                for (string& suffix : suffixes) {
                    result.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }
        
        dp[start] = result;
        return result;
    }
};
