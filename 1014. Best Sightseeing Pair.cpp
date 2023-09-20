class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxScore = 0;
        int maxI = A[0];

        for (int j = 1; j < A.size(); ++j) {
            maxScore = max(maxScore, maxI + A[j] - j);
            maxI = max(maxI, A[j] + j);
        }

        return maxScore;
    }
};
