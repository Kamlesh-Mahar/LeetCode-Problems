class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows = M.size();
        int cols = M[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int count = 0;
                int sum = 0;

                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < rows && y >= 0 && y < cols) {
                            count++;
                            sum += M[x][y];
                        }
                    }
                }

                result[i][j] = sum / count;
            }
        }

        return result;
    }
};
