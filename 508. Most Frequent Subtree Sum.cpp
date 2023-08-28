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
    unordered_map<int, int> freqMap;
    
    int subtreeSum(TreeNode* root) {
        if (!root) return 0;
        
        int leftSum = subtreeSum(root->left);
        int rightSum = subtreeSum(root->right);
        int totalSum = leftSum + rightSum + root->val;
        
        ++freqMap[totalSum];
        
        return totalSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        subtreeSum(root);
        
        int maxFreq = 0;
        for (const auto& pair : freqMap) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
            }
        }
        
        for (const auto& pair : freqMap) {
            if (pair.second == maxFreq) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};
