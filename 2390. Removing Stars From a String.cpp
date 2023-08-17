class Solution {
public:
    string removeStars(string s) {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == '*') {
                if (!st.empty()) {
                    st.pop(); 
                }
            } else {
                st.push({c, i});
            }
        }
        string result;
        while (!st.empty()) {
            result += st.top().first;
            st.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};
