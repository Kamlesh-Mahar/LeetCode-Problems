class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        
        for (int i = 1; i <= num; ++i) {
            result[i] = result[i >> 1] + (i & 1);
        }
        
        return result;
    }
};
