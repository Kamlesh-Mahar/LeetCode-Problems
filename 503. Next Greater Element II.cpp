#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  
        stack<int> st;
        for (int i = 0; i < n * 2; ++i) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                result[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }

        return result;
    }
};
