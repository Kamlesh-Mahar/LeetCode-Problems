#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        vector<string> phoneMap = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        string current;
        backtrack(digits, 0, phoneMap, current, result);
        
        return result;
    }

private:
    void backtrack(const string& digits, int index, const vector<string>& phoneMap, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        string letters = phoneMap[digit - 2];
        
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, phoneMap, current, result);
            current.pop_back();
        }
    }
};