class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, k, n, 1);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& current, int k, int target, int start) {
        if (k == 0 && target == 0) {
            result.push_back(current);
            return;
        }

        if (k == 0 || target < 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            current.push_back(i);
            backtrack(result, current, k - 1, target - i, i + 1);
            current.pop_back();
        }
    }
};
