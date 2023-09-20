class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int targetSum = accumulate(nums.begin(), nums.end(), 0) - x;
        
        if (targetSum < 0) {
            return -1; 
        }
        
        if (targetSum == 0) {
            return n;
        }

        int minLength = INT_MAX;
        int left = 0;
        int currentSum = 0;

        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];

            while (currentSum > targetSum) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == targetSum) {
                minLength = min(minLength, n - (right - left + 1));
            }
        }

        return (minLength == INT_MAX) ? -1 : minLength;
    }
};
