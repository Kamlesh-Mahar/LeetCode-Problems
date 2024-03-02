class Solution {
public:
    vector<int> sortedSquares(std::vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            result[i] = nums[i] * nums[i];
        }

        sort(result.begin(), result.end());

        return result;
    }
};
