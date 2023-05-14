

       ------------------- //C++  solution----------------
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto token : tokens) {
            if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
                nums.push(stoi(token));
            } else {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                if (token == "+") {
                    nums.push(a + b);
                } else if (token == "-") {
                    nums.push(a - b);
                } else if (token == "*") {
                    nums.push(a * b);
                } else if (token == "/") {
                    nums.push(a / b);
                }
            }
        }
        return nums.top();
    }
};



      ---------------------JS-------------------------


/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const stack = [];
    for (let i = 0; i < tokens.length; i++) {
        const token = tokens[i];
        if (/\d/.test(token)) {
            stack.push(Number(token));
        } else {
            const b = stack.pop();
            const a = stack.pop();
            switch (token) {
                case "+":
                    stack.push(a + b);
                    break;
                case "-":
                    stack.push(a - b);
                    break;
                case "*":
                    stack.push(a * b);
                    break;
                case "/":
                    stack.push(Math.trunc(a / b));
                    break;
            }
        }
    }
    return stack[0];
};
