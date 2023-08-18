class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0; 
        
        queue<string> q;
        q.push(beginWord);
        int ladderLength = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string currWord = q.front();
                q.pop();
                
                if (currWord == endWord) return ladderLength;
                
                for (int j = 0; j < currWord.length(); ++j) {
                    char originalChar = currWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        
                        currWord[j] = c;
                        if (wordSet.find(currWord) != wordSet.end()) {
                            q.push(currWord);
                            wordSet.erase(currWord); 
                        }
                    }
                    currWord[j] = originalChar;
                }
            }
            ++ladderLength;
        }
        
        return 0; 
    }
};
