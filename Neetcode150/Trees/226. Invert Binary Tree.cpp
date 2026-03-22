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

        TreeNode* temp = left; 
        root->left = right; 
        root->right = temp; 

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
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); 
                q.pop(); 

                TreeNode* temp = curr->left; 
                curr->left = curr->right; 
                curr->right = temp; 

                if(curr->left) q.push(curr->left); 
                if(curr->right) q.push(curr->right); 
            }
        }
        return root; 
    }
};
