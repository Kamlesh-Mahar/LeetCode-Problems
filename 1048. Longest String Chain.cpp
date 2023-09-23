class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        unordered_map<string, int> dp;
        
        int maxChainLength = 1; 
        
        for (string word : words) {
            int currentChainLength = 1;
            for (int i = 0; i < word.size(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(predecessor) != dp.end()) {
                    currentChainLength = max(currentChainLength, dp[predecessor] + 1);
                }
            }
            
            dp[word] = currentChainLength;
            maxChainLength = max(maxChainLength, currentChainLength);
        }
        
        return maxChainLength;
    }
};
