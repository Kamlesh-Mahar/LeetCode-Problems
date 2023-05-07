class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int count = que.size(); 
            vector<int> level;
            for(int i=0; i<count; ++i){
                TreeNode *node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;

    }
};