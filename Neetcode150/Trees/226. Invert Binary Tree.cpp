//recursive solution 
//TC: O(N) SC: O(H)
//balance tree space O(logn)
//skweed worst case O(N)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL; 

        TreeNode* left = invertTree(root->left); 
        TreeNode* right = invertTree(root->right); 

        root->left = right;
        root->right = left; 

        return root; 
    }
};

//iterative + swap 
//TC: O(N) SC: O(N)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL; 

        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()){
            TreeNode* node = q.front(); 
            q.pop(); 
            swap(node->left, node->right); 
            if(node->left){
                q.push(node->left); 
            }
            if(node->right){
                q.push(node->right); 
            }
        }
        return root; 
    }
};
