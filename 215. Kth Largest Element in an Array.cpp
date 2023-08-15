class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (nums[j] >= pivot) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    int quickSelect(vector<int>& nums, int low, int high, int k) {
        if (low <= high) {
            int pivotIndex = partition(nums, low, high);
            if (pivotIndex == k - 1) {
                return nums[pivotIndex];
            } else if (pivotIndex < k - 1) {
                return quickSelect(nums, pivotIndex + 1, high, k);
            } else {
                return quickSelect(nums, low, pivotIndex - 1, k);
            }
        }
        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};