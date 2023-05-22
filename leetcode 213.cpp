class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int maxAmount1 = robHelper(nums, 0, n - 2);
        int maxAmount2 = robHelper(nums, 1, n - 1);
        return max(maxAmount1, maxAmount2);
    }
    
    int robHelper(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;  
        
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};