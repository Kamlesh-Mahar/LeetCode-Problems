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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0; 

        while (!q.empty()) {
            int size = q.size();
            int prevValue = level % 2 == 0 ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();

                if (level % 2 == 0) { 
                    if (current->val % 2 == 0 || current->val <= prevValue) {
                        return false;
                    }
                } else { 
                    if (current->val % 2 == 1 || current->val >= prevValue) {
                        return false;
                    }
                }

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }

                prevValue = current->val;
            }

            ++level;
        }

        return true;
    }
};
