#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};
