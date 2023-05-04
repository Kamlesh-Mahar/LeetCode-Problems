class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin = 0, rowEnd = matrix.size()-1;
        int colBegin = 0, colEnd = matrix[0].size()-1;
        vector<int> result;
        
        while(rowBegin <= rowEnd && colBegin <= colEnd) {
            // Traverse right
            for(int j=colBegin; j<=colEnd; j++) {
                result.push_back(matrix[rowBegin][j]);
            }
            rowBegin++;
            
            // Traverse down
            for(int i=rowBegin; i<=rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            
            // Traverse left
            if(rowBegin <= rowEnd) {
                for(int j=colEnd; j>=colBegin; j--) {
                    result.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--;
            
            // Traverse up
            if(colBegin <= colEnd) {
                for(int i=rowEnd; i>=rowBegin; i--) {
                    result.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++;
        }
        
        return result;
    }
};

