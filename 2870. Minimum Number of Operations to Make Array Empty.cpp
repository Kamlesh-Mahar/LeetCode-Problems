class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [_, freq] : count) {
      if (freq == 1)
        return -1;
      ans += (freq + 2) / 3;
    }

    return ans;
  }
};
