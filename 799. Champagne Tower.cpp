class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(query_row + 1, vector<double>(query_row + 1, 0.0));
        glasses[0][0] = static_cast<double>(poured);
        for (int row = 0; row <= query_row; row++) {
            for (int col = 0; col <= row; col++) {
                double overflow = (glasses[row][col] - 1.0) / 2.0; 
                if (overflow > 0) {
                    glasses[row][col] = 1.0;
                    if (row + 1 <= query_row) {
                        glasses[row + 1][col] += overflow; 
                        glasses[row + 1][col + 1] += overflow;
                    }
                }
            }
        }
        return min(1.0, glasses[query_row][query_glass]);
    }
};
