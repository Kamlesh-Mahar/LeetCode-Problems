class Solution {
public:
    unordered_map<long, int> map;
    int count = 0;
    
    void countPathSum(TreeNode* root, int target, long sum){
        if(!root)
            return;
        sum += root->val;        
        if(sum == target)
            count++;
        if(map.find(sum - target) != map.end()) 
            count += map[sum - target];
        map[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        map[sum]--;   
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countPathSum(root, targetSum, 0);
        return count;
    }
};
