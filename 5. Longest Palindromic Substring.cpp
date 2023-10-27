class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }

        int start = 0; 
        int maxLength = 1; 
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1; 

                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                    if (length > maxLength) {
                        start = i;
                        maxLength = length;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
