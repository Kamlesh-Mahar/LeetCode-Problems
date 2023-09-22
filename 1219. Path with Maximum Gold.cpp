class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    int currentGold = dfs(grid, i, j);
                    maxGold = max(maxGold, currentGold);
                }
            }
        }

        return maxGold;
    }

private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }

        int temp = grid[row][col]; 
        grid[row][col] = 0; 

        int up = dfs(grid, row - 1, col);
        int down = dfs(grid, row + 1, col);
        int left = dfs(grid, row, col - 1);
        int right = dfs(grid, row, col + 1);

        grid[row][col] = temp; 

        return temp + max(max(up, down), max(left, right)); 
    }
};
