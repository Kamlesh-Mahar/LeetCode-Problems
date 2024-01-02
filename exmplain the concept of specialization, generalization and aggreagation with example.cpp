class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> count(nums.size() + 1);

    for (const int num : nums) {
      if (++count[num] > ans.size())
        ans.push_back({});
      ans[count[num] - 1].push_back(num);
    }

    return ans;
  }
};
