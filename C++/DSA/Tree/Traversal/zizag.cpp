//ZIGZAG Traversal ......
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>ans; 
        if(!root) return ans;
         
        queue<TreeNode*>q;
        q.push(root);
        
        bool flag=true;
        
        while(!q.empty())
        {
            int s=q.size();
            
            vector<int>v(s);
            for(int i=0;i<s;i++)
            {
                TreeNode* tmp=q.front();
                q.pop();
                
                int ind=flag?i:(s-i-1);
                v[ind]=tmp->val;
                
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
                
            }
            flag=!flag;
            ans.push_back(v);
        }
        return ans;
    }
};