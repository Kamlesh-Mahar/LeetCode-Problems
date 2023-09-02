class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowelCount = 0;
        int currentVowelCount = 0;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }
        }

        maxVowelCount = currentVowelCount;

        for (int i = k; i < s.size(); ++i) {
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }

            if (vowels.count(s[i - k])) {
                currentVowelCount--;
            }

            maxVowelCount = max(maxVowelCount, currentVowelCount);
            if (maxVowelCount == k) {
                return k;
            }
        }

        return maxVowelCount;
    }
};
