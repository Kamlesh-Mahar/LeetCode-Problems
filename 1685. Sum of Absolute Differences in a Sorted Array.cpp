class Solution {
public:
    vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        int prefixSum = 0;
        int suffixSum = 0;

        for (int num : nums) {
            suffixSum += num;
        }

        for (int i = 0; i < n; ++i) {
            result[i] = (nums[i] * i - prefixSum) + (suffixSum - nums[i] * (n - i));
            prefixSum += nums[i];
            suffixSum -= nums[i];
        }

        return result;
    }

};
