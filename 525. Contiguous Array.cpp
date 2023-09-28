class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> balance; 
        int maxLen = 0;
        int currentBalance = 0;
        balance[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                currentBalance--;
            } else {
                currentBalance++;
            }
            if (balance.find(currentBalance) != balance.end()) {
                maxLen = max(maxLen, i - balance[currentBalance]);
            } else {
                balance[currentBalance] = i;
            }
        }

        return maxLen;
    }
};
