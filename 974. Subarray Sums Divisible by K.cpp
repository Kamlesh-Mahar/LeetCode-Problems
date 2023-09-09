#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int N = A.size();
        vector<int> prefixSum(N + 1, 0);
        unordered_map<int, int> remainderCount; 
        int count = 0;

        remainderCount[0] = 1;

        for (int i = 0; i < N; ++i) {
            prefixSum[i + 1] = prefixSum[i] + A[i];
            int remainder = (prefixSum[i + 1] % K + K) % K; 

            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }

            remainderCount[remainder]++;
        }

        return count;
    }
};
