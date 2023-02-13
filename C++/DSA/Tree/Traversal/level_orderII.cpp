
// LEVEL ORDER TRAVERSAL II from bottom...

BFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;
        
         if(!root)return ans;
        
         queue<TreeNode*>q;
         q.push(root);
        
         while(!q.empty())
         {
             vector<int>tmp;
             int n=q.size();
             
             for(int i=0;i<n;i++)
             {
             TreeNode* node=q.front();
             q.pop();
             tmp.push_back(node->val);
             if(node->left)q.push(node->left);
             if(node->right)q.push(node->right);
             }
             ans.push_back(tmp);
             
         }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};