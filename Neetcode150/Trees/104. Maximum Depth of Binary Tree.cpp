//bfs iterative - basically how many levels in a tree 
//TC: O(N) SC: O(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 

        int depth = 0; 
        queue<TreeNode*> q; 

        q.push(root); 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); 
                q.pop();

                if(node->left){
                    q.push(node->left); 
                }   
                if(node->right){
                    q.push(node->right); 
                }
            }
            depth++; 
        }
        return depth; 
    }
};

//dfs recursion 
//TC: O(N) SC: O(H)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 

        int left = maxDepth(root->left); 
        int right = maxDepth(root->right); 

        return 1 + max(left, right); 
    }
};