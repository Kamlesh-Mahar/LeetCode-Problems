class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3);
        
        for (int i = 0; i < n; ++i) {
            vector<int> new_dp = dp;
            for (int j = 0; j < 3; ++j) {
                int new_remainder = (dp[j] + nums[i]) % 3;
                new_dp[new_remainder] = max(new_dp[new_remainder], dp[j] + nums[i]);
            }
            
            dp = new_dp; 
        }
        
        return dp[0]; 
    }
};
