class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    vector<int> dp(nums.size());
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
      if (dq.empty())
        dp[i] = nums[i];
      else
        dp[i] = max(dq.front(), 0) + nums[i];
      while (!dq.empty() && dq.back() < dp[i])
        dq.pop_back();
      dq.push_back(dp[i]);
      if (i >= k && dp[i - k] == dq.front())
        dq.pop_front();
    }

    return ranges::max(dp);
  }
};
