class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double left = 0.0;
        double right = 1.0;

        while (left < right) {
            double mid = (left + right) / 2;
            int count = 0;
            double maxFraction = 0.0;
            pair<int, int> resultFraction;

            int j = 0;
            for (int i = 0; i < A.size(); i++) {
                while (j < A.size() && A[i] > mid * A[j]) {
                    j++;
                }

                if (j == A.size()) {
                    break; 
                }

                count += (A.size() - j);
                double currentFraction = static_cast<double>(A[i]) / A[j];
                
                if (currentFraction > maxFraction) {
                    maxFraction = currentFraction;
                    resultFraction = make_pair(A[i], A[j]);
                }
            }

            if (count == K) {
                return { resultFraction.first, resultFraction.second };
            } else if (count < K) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return {}; 
    }
};
