class Solution {
public:
    int maxScore(string s) {
        int zerosOnRight = 0;
        int onesOnLeft = 0;
        for (char ch : s) {
            if (ch == '1') {
                onesOnLeft++;
            }
        }

        int maxScore = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                zerosOnRight++;
            } else {
                onesOnLeft--;
            }

            int currentScore = zerosOnRight + onesOnLeft;
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};
