class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right;
        if (!root) return right;
        rightSideViewRecursive(root, right, 0);
        return right;
    }
private:
    void rightSideViewRecursive(TreeNode* node, vector<int>& right, int level) {
        if (!node) return;
        if (level == right.size()) {
            right.push_back(node->val);
        }
        rightSideViewRecursive(node->right, right, level + 1);
        rightSideViewRecursive(node->left, right, level + 1);
    }
};