//TC:O (n^2) SC: O(h)
//calc the height of the LST and RST for each node and see if the diff is > 1 
//if not, check traverse to the left and right root and check if they are balanced 
class Solution {
public:

    int heightTree(TreeNode* root){
        if(root == NULL) return 0; 

        int left = heightTree(root->left); 
        int right = heightTree(root->right); 

        return max(left, right)+1; 
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true; 

        int left = heightTree(root->left); 
        int right = heightTree(root->right); 

        int diff = abs(left-right); 
        if(diff > 1) return false; 
        return isBalanced(root->left) && isBalanced(root->right); 
    }
};