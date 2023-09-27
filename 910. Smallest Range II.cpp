class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());
        int minDiff = A[n - 1] - A[0]; 
        for (int i = 0; i < n - 1; i++) {
            int maxVal = max(A[i] + K, A[n - 1] - K);
            int minVal = min(A[0] + K, A[i + 1] - K);
            minDiff = min(minDiff, maxVal - minVal);
        }

        return minDiff;
    }
};
