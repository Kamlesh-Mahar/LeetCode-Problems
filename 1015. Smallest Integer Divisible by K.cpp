class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1; 
        }
        
        int remainder = 0;
        for (int length = 1; length <= K; ++length) {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0) {
                return length;
            }
        }
        
        return -1; 
    }
};
