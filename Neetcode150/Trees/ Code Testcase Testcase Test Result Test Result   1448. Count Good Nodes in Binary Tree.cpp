//TC: O(n) SC: O(h)
class Solution {
public:

    int count = 0; 

    int countGoodNodes(TreeNode* root, int maxVal){
        if(root == NULL) return 0; 

        if(root->val >= maxVal){
            count++; 
            maxVal = max(maxVal, root->val); 
        }
        countGoodNodes(root->left, maxVal); 
        countGoodNodes(root->right, maxVal); 
        return count; 
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val); 
    }
};