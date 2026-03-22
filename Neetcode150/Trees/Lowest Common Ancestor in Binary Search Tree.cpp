//dfs recursive 
//TC: O(H) SC: O(H)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q); 
        }else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q); 
        }else{
            return root; 
        }
    }
};

//dfs iterative
//TC: O(H) SC: O(H)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root; 

        while(curr){
            if(curr->val > p->val && curr->val > q->val){
                curr = curr->left; 
            }else if(curr->val < p->val && curr->val < q->val){
                curr = curr->right; 
            }else{
                return curr; 
            }
        }
    }
};