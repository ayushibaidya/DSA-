//TC: O(n) SC: O(n)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true; 

        if(p == NULL || q == NULL) return false; 

        if(p->val != q->val) return false; 
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }
};

//TC: O(n)
//SC: O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true; 

        queue<pair<TreeNode*, TreeNode*>> qu; 
        qu.push({p, q}); 

        while(!qu.empty()){
            int size = qu.size(); 
            for(int i = 0; i < size; i++){
                TreeNode* pCurr = qu.front().first; 
                TreeNode* qCurr = qu.front().second; 
                qu.pop();
                if(!pCurr && !qCurr) continue; 
                if(!pCurr || !qCurr) return false; 
                if(pCurr->val != qCurr->val) return false;  
                qu.push({pCurr->left, qCurr->left}); 
                qu.push({pCurr->right, qCurr->right}); 
            }
        }
        return true; 
    }
};