class Solution {
public:
    #include <vector>

int numSpecial(std::vector<std::vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<int> rowSum(rows, 0);
    vector<int> colSum(cols, 0);
    int specialCount = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSum[i] += mat[i][j];
            colSum[j] += mat[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                specialCount++;
            }
        }
    }

    return specialCount;
}

};
