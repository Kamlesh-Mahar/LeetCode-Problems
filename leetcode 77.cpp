class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        helperfun(n, k, 1, combination, result);
        return result;
    }
    
    void helperfun(int n, int k, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            helperfun(n, k-1, i+1, combination, result);
            combination.pop_back();
        }
    }
};