class Solution{
    public: 

    TreeNode buildNode(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> inorder_map){
        if(preStart > preEnd || inStart > inEnd){
            return NULL; 
        }

        TreeNode* root = new TreeNode(preorder[preStart]); 
        int inRoot = inorder_map[root->val]; 
        int numsLeft = inRoot-inStart; 

        root->left = buildNodes(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inorder_map); 
        root->right = buildNodes(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inorder_map); 

        return root; 
    }

    //preorder will give the root [0] -> root
    //inorder -> find root in inorder, left of root index is LST, right 
        //of root index is RST 

    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
        int n = inorder.size(); 

        unordered_map<int, int> inorder_map; 
        for(int i = 0; i < n; i++){
            inorder_map[inorder[i]] = i; 
        }

        TreeNode* root = buildNodes(preorder, 0, n-1, inorder, 0, n-1, inorder_map); 

        return root; 
    }
}