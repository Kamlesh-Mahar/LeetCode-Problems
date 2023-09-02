class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int left = 0;
        int zeroCount = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left);
        }
        
        return maxLen;
    }
};
