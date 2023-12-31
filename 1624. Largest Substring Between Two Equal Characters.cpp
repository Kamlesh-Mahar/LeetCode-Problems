class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> lastOccurrence;
        int maxLength = -1;

        for (int i = 0; i < s.size(); ++i) {
            if (lastOccurrence.find(s[i]) == lastOccurrence.end()) {
                lastOccurrence[s[i]] = i;
            } else {
                maxLength = max(maxLength, i - lastOccurrence[s[i]] - 1);
            }
        }

        return maxLength;
    }
};
