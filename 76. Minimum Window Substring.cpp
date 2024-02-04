class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCount;
        int requiredChars = t.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, minLeft = 0;

        for (char ch : t) {
            charCount[ch]++;
        }

        while (right < s.size()) {
            if (charCount[s[right]] > 0) {
                requiredChars--;
            }
            charCount[s[right]]--;
            right++;

            while (requiredChars == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minLeft = left;
                }

                charCount[s[left]]++;
                if (charCount[s[left]] > 0) {
                    requiredChars++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
