class Solution {
public:
    vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l,    vector<int>& r) {
    int n = nums.size();
    int m = l.size();
    vector<bool> result;

    for (int i = 0; i < m; ++i) {
        int left = l[i];
        int right = r[i];

        vector<int> subarray(nums.begin() + left, nums.begin() + right + 1);
        sort(subarray.begin(), subarray.end());

        bool isArithmetic = true;

        for (int j = 2; j < subarray.size(); ++j) {
            if (subarray[j] - subarray[j - 1] != subarray[1] - subarray[0]) {
                isArithmetic = false;
                break;
            }
        }

        result.push_back(isArithmetic);
    }

    return result;
}
};
