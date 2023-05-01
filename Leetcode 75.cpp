// keeping track of three pointers left, right and i and swapping.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int i = 0;
        
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                i++;
                left++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }
            else {
                i++;
            }
        }
    }
};

//time complexity of O(n) and a space complexity of O(1).

