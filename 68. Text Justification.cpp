class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        
        int i = 0;
        while (i < words.size()) {
            int j = i, lineLength = 0;
            while (j < words.size() && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            
            int extraSpaces = maxWidth - lineLength;
            int numWords = j - i;
            
            string line = words[i];
            for (int k = i + 1; k < j; ++k) {
                if (j == words.size()) { 
                    line += " ";
                } else {
                    line += string(extraSpaces / (numWords - 1) + (k - i <= extraSpaces % (numWords - 1)), ' ');
                }
                line += words[k];
            }
            
            while (line.length() < maxWidth) {
                line += " ";
            }
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};
