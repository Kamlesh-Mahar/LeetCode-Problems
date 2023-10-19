class Solution {
public:
    bool backspaceCompare(std::string S, std::string T) {
        return processString(S) == processString(T);
    }

private:
    string processString(const std::string& str) {
        std::string result;
        
        for (char ch : str) {
            if (ch == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};
