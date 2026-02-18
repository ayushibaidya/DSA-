class Solution {
public:

    int maxSum(TreeNode* root, int &res){
        if(root == NULL) return 0; 

        int left = max(0, maxSum(root->left, res)); 
        int right = max(0, maxSum(root->right, res)); 

        res = max(res, left+right+root->val); 
        return root->val + max(left, right); 
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN; 
        maxSum(root, res); 
        return res; 
    }
};
