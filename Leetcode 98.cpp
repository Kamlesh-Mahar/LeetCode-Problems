class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBSTHelper(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min|| root->val >= max) {
            return false;
        }
        return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
    }
};
