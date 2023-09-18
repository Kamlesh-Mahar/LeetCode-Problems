#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(); // Number of rows
        int n = mat[0].size(); // Number of columns

        vector<pair<int, int>> strength; // {number of 1s, row index}

        for (int i = 0; i < m; ++i) {
            int ones = countOnes(mat[i]);
            strength.push_back({ones, i});
        }

        // Sort the rows based on strength
        sort(strength.begin(), strength.end());

        vector<int> result;

        for (int i = 0; i < k; ++i) {
            result.push_back(strength[i].second);
        }

        return result;
    }

private:
    int countOnes(const vector<int>& row) {
        int count = 0;
        for (int num : row) {
            if (num == 1) {
                count++;
            }
        }
        return count;
    }
};
