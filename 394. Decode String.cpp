class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string result = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (isalpha(c)) {
                result += c;
            } else if (c == '[') {
                strStack.push(result);
                numStack.push(num);
                result = "";
                num = 0;
            } else if (c == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string prev = strStack.top();
                strStack.pop();
                for (int i = 0; i < repeat; i++) {
                    prev += result;
                }
                result = prev;
            }
        }

        return result;
    }
};
