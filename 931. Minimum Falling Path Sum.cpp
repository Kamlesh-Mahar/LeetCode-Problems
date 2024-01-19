class Solution {
public:
    int minFallingPathSum(vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == 0) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                } else if (j == cols - 1) {
                    matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
                } else {
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
                }
            }
        }

        return *min_element(matrix[rows - 1].begin(), matrix[rows - 1].end());
    }
};
