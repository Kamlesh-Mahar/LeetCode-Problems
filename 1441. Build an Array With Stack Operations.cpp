class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int targetIndex = 0;

        for (int i = 1; i <= n && targetIndex < target.size(); i++) {
            operations.push_back("Push");
            if (i != target[targetIndex]) {
                operations.push_back("Pop");
            } else {
                targetIndex++;
            }
        }

        return operations;
    }
};
