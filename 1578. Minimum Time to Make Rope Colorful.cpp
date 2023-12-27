class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    int ans = 0;
    int maxNeededTime = neededTime[0];

    for (int i = 1; i < colors.length(); ++i)
      if (colors[i] == colors[i - 1]) {
        ans += min(maxNeededTime, neededTime[i]);
        maxNeededTime = max(maxNeededTime, neededTime[i]);
      } else {
        maxNeededTime = neededTime[i];
      }

    return ans;
  }
};
