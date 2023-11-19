class Solution {
public:
    int reductionOperations(std::vector<int>& nums) {
    sort(nums.begin(), nums.end(), std::greater<int>());
    int operations = 0;
    int currentMax = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < currentMax) {
            currentMax = nums[i];
            operations += i;
        }
    }

    return operations;
}
};
