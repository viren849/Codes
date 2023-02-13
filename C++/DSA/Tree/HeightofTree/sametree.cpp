 
//SameTree.......
 bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p && !q)return true;
        if(p==NULL || q==NULL) return false;
        if(p->val != q->val)return false;
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
        
    }