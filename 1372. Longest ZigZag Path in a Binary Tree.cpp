/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        int longest = 0;
        dfs(root, longest, true, 0); 
        return longest;
    }

private:
    void dfs(TreeNode* node, int& longest, bool isLeft, int current) {
        if (!node) return;

        longest = max(longest, current);

        if (isLeft) {
            dfs(node->right, longest, false, current + 1);
            dfs(node->left, longest, true, 1);
        } else {
            dfs(node->left, longest, true, current + 1);
            dfs(node->right, longest, false, 1);
        }
    }
};
