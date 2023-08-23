class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
    
        bool hasDigits = false;
        while (i < n && isdigit(s[i])) {
            hasDigits = true;
            i++;
        }
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                hasDigits = true;
                i++;
            }
        }
        if (hasDigits && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                i++;
            }
            bool hasExponentDigits = false;
            while (i < n && isdigit(s[i])) {
                hasExponentDigits = true;
                i++;
            }
            if (!hasExponentDigits) {
                return false;
            }
        }
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        return hasDigits && i == n;
    }
};
