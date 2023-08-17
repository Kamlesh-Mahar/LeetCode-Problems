class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dub(m + 1, vector<bool>(n + 1, false));
        dub[0][0] = true; 
        
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dub[0][j] = dub[0][j - 1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dub[i][j] = dub[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dub[i][j] = dub[i - 1][j] || dub[i][j - 1];
                }
            }
        }
        return dub[m][n];
    }
};
