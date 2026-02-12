/*
we have to get a new count every iteration, count = 1 or 0 based on if there is a node
greater than the maxNode val 

therefore, we cannot pass the node count value as a parameter 

TC: O(n)
*/

class Solution{
    public: 
    int countGoodNodes(TreeNode* root, int maxNode){
        if(root == NULL) return 0; 

        int count = 0; 

        if(root->val >= maxNode){
            count = 1; 
        }

        maxNode = max(maxNode, root->val); 

        count += countGoodNodes(root->left, maxNode); 
        count += countGoodNodes(root->right, maxNode); 

        return count; 
    }

    int goodNodes(TreeNode* root){
        return countGoodNodes(root, root->val); 
    }
}