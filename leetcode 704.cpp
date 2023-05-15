class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1; 
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid; 
        } else if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, right); 
        } else {
            return binarySearch(nums, target, left, mid - 1);
        }
    }
};