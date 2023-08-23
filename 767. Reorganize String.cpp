class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> charCount;
        int maxFreq = 0;
        char maxChar = ' ';
        
        for (char c : S) {
            charCount[c]++;
            if (charCount[c] > maxFreq) {
                maxFreq = charCount[c];
                maxChar = c;
            }
        }
        
        if (maxFreq > (S.length() + 1) / 2) {
            return "";
        }
        
        string result(S.length(), ' ');
        int idx = 0;
        
        while (charCount[maxChar] > 0) {
            result[idx] = maxChar;
            idx += 2;
            charCount[maxChar]--;
        }
        
        for (auto entry : charCount) {
            while (entry.second > 0) {
                if (idx >= S.length()) {
                    idx = 1;
                }
                result[idx] = entry.first;
                idx += 2;
                entry.second--;
            }
        }
        
        return result;
    }
};
