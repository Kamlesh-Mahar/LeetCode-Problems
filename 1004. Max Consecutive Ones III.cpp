class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0;
        int maxOnes = 0;

        while (right < A.size()) {
            if (A[right] == 0) {
                K--; 
            }

            while (K < 0) {
                if (A[left] == 0) {
                    K++;
                }
                left++;
            }

            maxOnes = max(maxOnes, right - left + 1);
            right++;
        }

        return maxOnes;
    }
};
