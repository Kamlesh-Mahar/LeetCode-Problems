class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowSet[9];
        unordered_set<char> colSet[9];
        unordered_set<char> boxSet[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    if (rowSet[i].count(c) || colSet[j].count(c) || boxSet[(i/3)*3 + j/3].count(c)) {
                        return false;
                    }
                    rowSet[i].insert(c);
                    colSet[j].insert(c);
                    boxSet[(i/3)*3 + j/3].insert(c);
                }
            }
        }
        return true;
    }
};
