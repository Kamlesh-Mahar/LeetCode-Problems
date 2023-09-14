class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (const auto& entry : wordCount) {
            const string& word = entry.first;
            int wordCount = entry.second;
            
            if (isSubsequence(S, word)) {
                count += wordCount;
            }
        }

        return count;
    }

private:
    bool isSubsequence(const string& s, const string& word) {
        int i = 0;
        int j = 0;

        while (i < s.length() && j < word.length()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }

        return j == word.length();
    }
};
