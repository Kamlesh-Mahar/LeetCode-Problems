class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false; 

        int left = 0;
        int right = static_cast<int>(sqrt(c)); 

        while (left <= right) {
            long long sum = static_cast<long long>(left) * left + static_cast<long long>(right) * right;
            
            if (sum == c) {
                return true; 
            } else if (sum < c) {
                left++; 
            } else {
                right--; 
            }
        }

        return false; 
    }
};
