class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0); 
        vector<bool> used(26, false);
        string result = ""; 

        for (char ch : s) {
            count[ch - 'a']++; 
        }

        for (char ch : s) {
            count[ch - 'a']--; 
            if (used[ch - 'a']) {
                continue;
            }
            while (!result.empty() && result.back() > ch && count[result.back() - 'a'] > 0) {
                used[result.back() - 'a'] = false; 
                result.pop_back(); 
            }
            result += ch;
            used[ch - 'a'] = true;
        }

        return result;
    }
};
