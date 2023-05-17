class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) {
            return false;
        }
        
        if (isSameTree(s, t)) {
            return true;
        }
        
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        
        if (!p || !q) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
