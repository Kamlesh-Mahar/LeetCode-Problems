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
  int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    int rank = 0;
    traverse(root, k, rank, ans);
    return ans;
  }

 private:
  void traverse(TreeNode* root, int k, int& rank, int& ans) {
    if (root == nullptr)
      return;

    traverse(root->left, k, rank, ans);
    if (++rank == k) {
      ans = root->val;
      return;
    }
    traverse(root->right, k, rank, ans);
  }
};
