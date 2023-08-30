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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
      return nullptr;
    if (root->val == key) {
      if (root->left == nullptr)
        return root->right;
      if (root->right == nullptr)
        return root->left;
      TreeNode* minNode = getMin(root->right);
      root->right = deleteNode(root->right, minNode->val);
      minNode->left = root->left;
      minNode->right = root->right;
      root = minNode;
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else { 
      root->left = deleteNode(root->left, key);
    }
    return root;
  }

 private:
  TreeNode* getMin(TreeNode* node) {
    while (node->left)
      node = node->left;
    return node;
  }
};
