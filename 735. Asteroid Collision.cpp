#include <vector>
#include <stack>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int asteroid : asteroids) {
            if (stk.empty() || asteroid > 0) {
                stk.push(asteroid);
            } else {
                while (!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroid)) {
                    stk.pop();
                }
                if (stk.empty() || stk.top() < 0) {
                    stk.push(asteroid);
                } else if (stk.top() == abs(asteroid)) {
                    stk.pop();
                }
            }
        }
        
        vector<int> result(stk.size());
        int i = stk.size() - 1;
        while (!stk.empty()) {
            result[i--] = stk.top();
            stk.pop();
        }
        
        return result;
    }
};
